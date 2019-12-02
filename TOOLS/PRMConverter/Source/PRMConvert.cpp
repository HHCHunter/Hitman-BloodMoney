//Hitman PRM to Obj converter 0.1 (8/12/2006)
//John "Cryect" Rittenhouse

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *Input,*Output;

char	*f;
int		FileSize;

typedef unsigned int uint;


struct Header{
	uint	ChunkPos;
	uint	ChunkNum;
	uint	ChunkPos2;
	uint	Zero;
};

struct Chunk{
	uint	Pos;
	uint	Size;
	uint	Unk1;
	uint	Unk2;
};

//Vertex Size - 0x10
struct Vertex1{
	float	Pos[3];
	int	unk1;
};

//Vertex Size - 0x24
struct Vertex4{
	float	Pos[3];
	float	Tex[2];
	int		unk1[2];
	float	Tex2[2];
};

//Vertex Size - 0x28
struct Vertex2{
	float	Pos[3];
	int	unk1[2];
	float	Tex[2];
	int	unk2[3];
};

//Vertex Size - 0x34
struct Vertex3{
	float	Pos[3];
	float	unk1[3];
	int		unk2[3];
	float	Tex[2];
	int		unk3[2];
};

struct	Descripter{
	int	Num1;
	int	VertChunk;
	int	Unk2;
	int	TriChunk;
};

struct ModelObject{
	int	unk1[10];
	int	ptrModel;
	int unk2[4];
	int	ptrUkn;
};

struct	ModelFile{
	int	unk1[3];
	int	unk2;		
	int	ptrParts;	
	int	numObjects;	//Number of objects for this model
	int	ptrObjects;	//ptr to the Object List which is just a list of ints that point to ModelObjects
	int	unk3;
	float	Extents[2][3];	//Extents of this model
};


Header	*header;
Chunk	*chunks;
int modelnum;

int main(int argc, char **argv)
{
	char t,fname[256];
	int i,j;


	printf("PRM to OBJ Converter 0.3 (8/14/2006)\n");
	printf("by John \"Cryect\" Rittenhouse\n");
	if(argc!=2)
	{
		printf("PRMConvert <PRM File>\n");
		return 0;
	}
	Input=fopen(argv[1],"rb+");

	if(Input==NULL)
	{
		printf(" ERROR: Could not load file %s\n",argv[1]);
		return 0;
	}

	fseek(Input,0,SEEK_END);
	FileSize=ftell(Input);
	fseek(Input,0,SEEK_SET);

	f=new char[FileSize];
	
	fread(f,FileSize,1,Input);
	fclose(Input);

	header=(Header *)f;
	chunks=(Chunk *)(f+header->ChunkPos);

	for(i=0;i<header->ChunkNum;i++)
	{
		ModelFile *Model;
		//Model Files have to be 0x40 bytes
		if(chunks[i].Size!=0x40)
			continue;
		
		Model=(ModelFile *)(f+chunks[i].Pos);

		//Ensure this is actually a model file
		if(Model->ptrParts>=header->ChunkNum)
			continue;
		if(Model->ptrObjects>=header->ChunkNum)
			continue;

		bool validExtents=true;
		for (j=0;j<3;j++)
		{
			if(Model->Extents[0][j]>Model->Extents[1][j])
				validExtents=false;
		}

		if(!validExtents)
			continue;

		if((Model->numObjects*4)>(chunks[Model->ptrObjects].Size))
			continue;

		unsigned int *objects;
		objects=(unsigned int *)(chunks[Model->ptrObjects].Pos+f);

		sprintf(fname,"model_%05d(%d).obj",modelnum,i);
				
		Output=fopen(fname,"wt");
		int TriOffset=1;
		for(int k=0;k<Model->numObjects;k++)
		{
			ModelObject *object;
			unsigned int Check;
			int vertexSize;

			if(objects[k]>=header->ChunkNum)
				continue;
			
			object=(ModelObject *)(f+chunks[objects[k]].Pos);

			if(object->ptrModel>=header->ChunkNum)
				continue;
			
			Check=*(unsigned int *)(f+chunks[object->ptrModel].Pos);

			if(Check>=header->ChunkNum)
				continue;


			Descripter *d;
			unsigned short *nTris;
			unsigned short *Tris;

			
			d=(Descripter *)(f+chunks[Check].Pos);

			if(d->Num1==0)
				continue;

			nTris=(unsigned short *)(f+chunks[d->TriChunk].Pos+2);
			Tris=(unsigned short *)(f+chunks[d->TriChunk].Pos+4);

			fprintf(Output,"g Object_%d\n",k);
			vertexSize=chunks[d->VertChunk].Size/d->Num1;
			vertexSize-=vertexSize%4;
			
			//Not sure how this happens exactly but sometimes its a multiple?
			if((vertexSize!=0x28)&&((vertexSize%0x28)==0))
			{
				d->Num1*=vertexSize/0x28;
				vertexSize=0x28;
				
			}
			if(vertexSize==0x10)
			{
				Vertex1 *v;
				v=(Vertex1 *)(f+chunks[d->VertChunk].Pos);

				for(j=0;j<d->Num1;j++)
					fprintf(Output,"v %f %f %f\n",v[j].Pos[0],v[j].Pos[1],v[j].Pos[2]);

				
				for(j=0;j<((*nTris)/3);j++)
					fprintf(Output,"f %d %d %d\n",Tris[j*3+2]+TriOffset,Tris[j*3+1]+TriOffset,Tris[j*3]+TriOffset);
				
			}
			else if(vertexSize==0x28)
			{
				Vertex2 *v;
				v=(Vertex2 *)(f+chunks[d->VertChunk].Pos);
				
				for(j=0;j<d->Num1;j++)
				{
					fprintf(Output,"v %f %f %f\n",v[j].Pos[0],v[j].Pos[1],v[j].Pos[2]);
					fprintf(Output,"vt %f %f 0.000000\n",v[j].Tex[0],1.0-v[j].Tex[1]);
				}

				
				for(j=0;j<((*nTris)/3);j++)
					fprintf(Output,"f %d/%d %d/%d %d/%d\n",Tris[j*3+2]+TriOffset,Tris[j*3+2]+TriOffset,Tris[j*3+1]+TriOffset,Tris[j*3+1]+TriOffset,Tris[j*3]+TriOffset,Tris[j*3]+TriOffset);
			}
			else if(vertexSize==0x34)
			{
				Vertex3 *v;
				v=(Vertex3 *)(f+chunks[d->VertChunk].Pos);
				

				for(j=0;j<d->Num1;j++)
				{
					fprintf(Output,"v %f %f %f\n",v[j].Pos[0],v[j].Pos[1],v[j].Pos[2]);
					fprintf(Output,"vt %f %f 0.000000\n",v[j].Tex[0],1.0-v[j].Tex[1]);
				}
				
				for(j=0;j<((*nTris)/3);j++)
					fprintf(Output,"f %d/%d %d/%d %d/%d\n",Tris[j*3+2]+TriOffset,Tris[j*3+2]+TriOffset,Tris[j*3+1]+TriOffset,Tris[j*3+1]+TriOffset,Tris[j*3]+TriOffset,Tris[j*3]+TriOffset);

			}
			else if(vertexSize==0x24)
			{
				Vertex4 *v;
				v=(Vertex4 *)(f+chunks[d->VertChunk].Pos);

				for(j=0;j<d->Num1;j++)
				{
					fprintf(Output,"v %f %f %f\n",v[j].Pos[0],v[j].Pos[1],v[j].Pos[2]);
					fprintf(Output,"vt %f %f 0.000000\n",v[j].Tex2[0],1.0-v[j].Tex2[1]);
				}

				
				for(j=0;j<((*nTris)/3);j++)
					fprintf(Output,"f %d/%d %d/%d %d/%d\n",Tris[j*3+2]+TriOffset,Tris[j*3+2]+TriOffset,Tris[j*3+1]+TriOffset,Tris[j*3+1]+TriOffset,Tris[j*3]+TriOffset,Tris[j*3]+TriOffset);
			}
			else if(vertexSize==0)
				continue;
			else
			{
				printf("Chunk %d has a vertex size of %x (possible model?) %d\n",d->VertChunk,vertexSize,chunks[d->VertChunk].Unk1);
				continue;
			}
			TriOffset+=d->Num1;
		}
		fclose(Output);
		modelnum++;
	}
	return 0;
}
