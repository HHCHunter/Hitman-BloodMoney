# Hitman: Blood Money - PRM to OBJ

A tool to dump PRM archives, which contain the model files used by the Glacier Engine for
Hitman Blood Money, to OBJ.

Originally written and developed by John "Cryect" Rittenhouse

https://twitter.com/cryect

Reports itself as *PRM to OBJ Converter 0.3 (8/14/2006)*. See
[Third-party components](../README.md#third-party-components) regarding licensing.

## Usage

Takes exactly one argument — the PRM file to dump:

```
PRMConvert <PRM File>
```

Each model found in the archive is written to the **current working directory** as a separate
file named `model_NNNNN(N).obj`, where the first number is the model index within the archive and
the second distinguishes sub-models. Run it from an empty directory, since a large archive
produces a lot of files.

Geometry and texture coordinates are exported. Materials are not, so the OBJ files reference no
MTL and will import untextured.

While scanning, the tool prints a line for any chunk whose vertex size it does not recognise,
noting it as a possible model. These are unhandled formats rather than errors.

## Contents

| Path | Notes |
|---|---|
| [`src/PRMConvert.cpp`](src/PRMConvert.cpp) | Complete source, single file. |
| [`bin/PRMConvert.exe`](bin/) | Prebuilt Windows binary from the original author, provided for convenience. |

The binary is included as originally distributed. If you would rather not run an unsigned
executable of unknown provenance, build from source instead — it is a single file with no
dependencies.

## Building

```
cl /EHsc src\PRMConvert.cpp
```

or with MinGW:

```
g++ -o PRMConvert.exe src/PRMConvert.cpp
```
