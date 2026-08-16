# Releases & Builds

A catalogue of every known release and build of *Hitman: Blood Money*, with its engine build
string decoded.

- [Reading a build string](#reading-a-build-string)
- [All known builds](#all-known-builds)
- [Demo distributions](#demo-distributions)
- [Recovering exact build timestamps](#recovering-exact-build-timestamps)
- [Sources](#sources)

---

## Reading a build string

Every build of the game carries a build string identifying the machine that produced it, the day
it was produced, and its source revision. All known strings follow the same shape:

```
blood-build3-20060616-26123
|     |      |        |
|     |      |        +-- revision: source-control counter, shared across all platforms
|     |      +----------- build date: YYYYMMDD
|     +----------------- build config / machine tag
+----------------------- project codename
```

The `BUILD DATE` and `REV` columns in the table below are decoded directly from this field. They
are not estimates. Each one is a literal reading of the string on that row.

### Prefix variants

The leading portion varies by platform and build machine, but the trailing
`-<YYYYMMDD>-<revision>` is universal.

| Prefix form           | Seen on                                          |
|-----------------------|--------------------------------------------------|
| `blood-build3-`       | PC, PS2                                          |
| `blood-build4-`       | PC, PS2                                          |
| `blood-build-ps2-`    | PS2 pre-release                                  |
| `blood-build-xenon-`  | Xbox 360 pre-release and retail (*Xenon* was the Xbox 360 dev codename) |
| `xbox-bloodbuild-`    | Original Xbox retail                             |
| `toolsbuild-`         | Xbox demo, built on the tools machine            |

Pre-release discs are also labelled with a shortened form of the same revision, as
`<revision>-PR`. The PS2 prototype below is named `21982-PR`, matching the `21982` in its build
string.

### `build3` / `build4` is not a version number

It is tempting to read `build4` as "newer than `build3`". It is not. The data contradicts it in
two places:

- `25595` (`build3`) and `25599` (`build4`) were produced on the **same day**, 2006-04-03.
- `build4`/`25990` (PC 1.0, 2006-05-08) **precedes** `build3`/`26039` (PC demo, 2006-05-17).

The number identifies the build configuration or machine, not a sequence. Order builds by the
`REV` column instead.

### The revision counter is global

The trailing counter is shared by every platform rather than being per-platform. Sorting all
builds that carry a build string by revision produces exactly the same order as sorting them by
date, with no crossovers between PC, PS2, Xbox or Xenon.

The Xbox 360 prototype is a useful check on this, because it was decoded after the pattern was
established rather than being part of the evidence for it. Its revision, `25691`, falls between
the PS2 retail builds at `25599` (2006-04-03) and the Xbox 360 retail build at `25827`
(2006-04-22), and its date, 2006-04-09, falls between theirs in exactly the same place.

That means revision numbers are **directly comparable across platforms**: build `25827` (Xenon)
genuinely is later work than build `25599` (PS2), not merely a higher number on a different
counter.

Across the known range the counter advances from `21662` (2006-01-12) to `26152` (2006-07-13):
4,490 revisions over 182 days, averaging roughly 25 per day. That average can suggest an
approximate date for a build string not listed here, but treat it as an estimate only. Commit
rates are never uniform, and the decode of the date field itself is exact and needs no such
inference.

---

## All known builds

Ordered chronologically. `BUILD DATE` is decoded from the build string where one is known; for
the prototypes, which have no recovered build string, it is the cataloguing date of the disc and
is marked accordingly.

| BUILD DATE | REV   | PLATFORM | TYPE      | VERSION | Release Type / Vendor   | Build String                     | REGION | TITLE ID           |
|------------|-------|----------|-----------|---------|-------------------------|----------------------------------|--------|--------------------|
| 2006-01-12 | 21662 | XBOX     | DEMO      |         | DEMO                    | toolsbuild-20060112-21662        | USA    | IM-32983           |
| 2006-01-18 | 21982 | PS2      | PROTOTYPE | 0.5     | BETA, `21982-PR`        | blood-build-ps2-20060118-21982   | EUR    | SLES-53028[^ps2id] |
| 2006-01-24 | 22440 | PS2      | DEMO      | 1.00    | DEMO                    | blood-build3-20060124-22440      | USA    | SLUS-29191         |
| 2006-02-02 | 22981 | PS2      | DEMO      |         | MAGAZINE COVER DISC     | blood-build3-20060202-22981      | EUR    | SCED-54044[^ops2m] |
| 2006-03-17 | 25332 | XBOX     | RETAIL    |         | PHYSICAL RETAIL RELEASE | xbox-bloodbuild-20060317-25332   | AUS    | 534300FA           |
| 2006-04-03 | 25595 | PS2      | RETAIL    | 1.01    | PHYSICAL RETAIL RELEASE | blood-build3-20060403-25595      | USA    | SLUS-21108         |
| 2006-04-03 | 25595 | PS2      | RETAIL    | 2.00    | PHYSICAL RETAIL RELEASE | blood-build3-20060403-25595      | EUR    | SLES-53028         |
| 2006-04-03 | 25599 | PS2      | RETAIL    | 1.00    | PHYSICAL RETAIL RELEASE | blood-build4-20060403-25599      | FRA    | SLES-53029         |
| 2006-04-03 | 25599 | PS2      | RETAIL    | 1.00    | PHYSICAL RETAIL RELEASE | blood-build4-20060403-25599      | GER    | SLES-53030         |
| 2006-04-03 | 25599 | PS2      | RETAIL    | 1.00    | PHYSICAL RETAIL RELEASE | blood-build4-20060403-25599      | ITA    | SLES-53031         |
| 2006-04-03 | 25599 | PS2      | RETAIL    | 1.00    | PHYSICAL RETAIL RELEASE | blood-build4-20060403-25599      | SPA    | SLES-53032         |
| 2006-04-09 | 25691 | Xbox 360 | PROTOTYPE |         | DVD-R[^apr11]           | blood-build-xenon-20060409-25691 |        | none assigned      |
| 2006-04-09 | 25691 | Xbox 360 | REVIEW    |         | DVD-R[^review]          | blood-build-xenon-20060409-25691 |        | none assigned      |
| 2006-04-22 | 25827 | Xbox 360 | RETAIL    | 0.0.0.9 | DIGITAL / Xbox Live     | blood-build-xenon-20060422-25827 | USA    | 534307DB           |
| 2006-05-08 | 25990 | PC       | RETAIL    | 1.0     | PHYSICAL RETAIL RELEASE | blood-build4-20060508-25990      | USA    |                    |
| 2006-05-08 | 25990 | PC       | RETAIL    | 1.0     | PHYSICAL RETAIL RELEASE | blood-build4-20060508-25990      | USA    | [^dup]             |
| 2006-05-17 | 26039 | PC       | DEMO      |         | DEMO                    | blood-build3-20060517-26039      |        |                    |
| 2006-06-01 | 26089 | PC       | RETAIL    | 1.2     | DIGITAL / STEAM         | blood-build3-20060601-26089      |        |                    |
| 2006-06-16 | 26123 | PC       | RETAIL    | 1.2     | DIGITAL / GOG           | blood-build3-20060616-26123      |        |                    |
| 2006-06-16 | 26123 | PC       | RETAIL    | 1.2     | PHYSICAL RETAIL RELEASE | blood-build3-20060616-26123      | UK     |                    |
| 2006-07-13 | 26152 | PC       | RETAIL    | 1.?     | ?                       | blood-build3-20060713-26152      | RUS    |                    |
| n/a        | n/a   | PS3      | RETAIL    |         | PHYSICAL RETAIL RELEASE | *unknown*                        | USA    | BLUS30942          |

[^ps2id]: Catalogued by Hidden Palace as the *Jan 20, 2006 prototype*, build name `21982-PR`,
serial `SLES-53028`. The serial is a PAL one, so the region is recorded here as EUR rather than
the USA given in earlier revisions of this table. It duplicates the PS2 EUR retail serial, which
is normal for a pre-release pressed before a dedicated serial was assigned, so this is no longer
treated as a data error. The disc contains only four playable missions: Training (M00), Curtains
Down (M03), Flatline (M04) and A House of Cards (M10); loading any other mission crashes on
missing files. Hidden Palace dates it Jan 20 against the build string's Jan 18, the usual gap
between building and pressing.

[^apr11]: The content-limited of the two Xbox 360 pre-release discs, corresponding to Hidden
Palace's *Apr 11, 2006 prototype* (released by ObscureGamers in Terarelease 3.0, original filename
`Hitman Blood Money (Apr 09, 2006).iso`). It ships scene data for only six missions (M00, M01,
M03, M04, M05, M06) plus Hideout, against the fifteen scene sets on the review disc, and a
correspondingly reduced set of movies. Its script DLLs nonetheless cover the full M00 to M13
range, so the restriction is in shipped content rather than in code.

[^review]: The complete of the two Xbox 360 pre-release discs, Hidden Palace's *Apr 12, 2006
prototype*, original filename `HITMAN_BM_REVIEW.iso`, build name "Review". This is an **Xbox 360**
disc, not an original Xbox one: the executable is `default.xex` (XEX2), the audio streams are
named `XBox2_Eng.s01` to `.s09`, and a `$SystemUpdate` directory is present. XDVDFS is used by
both consoles, so the filesystem alone does not settle it. Its XDVDFS volume descriptor FILETIME
is **2006-04-12 08:00:15 UTC**, three days after the executable was linked, which is why Hidden
Palace catalogues it under Apr 12. Hidden Palace records the build date as 2006-04-12 15:08:20,
pairing the disc date with the executable's time of day.

[^ops2m]: Read directly from `HITMAN/HITMAN.ELF` on the *Official PlayStation 2 Magazine* Demo
Disc 72 (Europe), volume `SCED_54044`, ISO 9660 volume created 2006-02-21 15:16:58, which is
nineteen days after the build. The identical executable, SHA-1
`B89A8634CF6184E4B775B79E82D8819BF4A01878`, also ships on the France disc (volume `SCED_54144`,
created 2006-03-13). The Germany disc numbered 72 (volume `SCED_54051`) is an unrelated
racing-themed compilation and contains no Hitman content at all, so regional disc numbering is
not consistent between editions. This is a distinct build from the standalone PS2 demo
`SLUS-29191` above, nine days later at 541 revisions further on.

[^dup]: This row duplicates the one above it verbatim in the source data. Retained rather than
deleted in case the two entries were meant to record distinct printings that were never
differentiated. Needs confirmation against physical media.

Reading the timeline: console versions were finished first, with all PS2 and Xbox retail builds
done by 2006-04-22, while the PC version continued for a further three months. The RUS release
was built almost two months after the PC version otherwise shipped. The Xbox demo at revision
`21662` is the earliest known build of the game on any platform, and the only one produced on the
`toolsbuild` machine.

### The two Xbox 360 pre-release discs share one executable

The prototype and review discs carry the **same build**, not two. Their `default.xex` files are
byte-identical, both 11,026,432 bytes at SHA-1
`F56A31867FD0F8CE3C4B182E07B2108B6CCB5E7B`, and their `main.ini` and `hmbgpad.cfg` match as well.
Both therefore report `blood-build-xenon-20060409-25691`.

What separates them is content. The prototype disc ships six missions' worth of scene data; the
review disc ships the full fifteen. Both carry the complete M00 to M13 script DLLs, so the
prototype is the same game with content withheld rather than an earlier state of development.

This also explains the dating spread across catalogues. One executable linked 2006-04-09 was
pressed onto at least two discs, mastered on later and differing dates, and each disc has since
been catalogued under the date of its pressing rather than the date of its build.

---

## Demo distributions

The demo builds in the table above reached the public through several different discs and
downloads. These are distribution vehicles rather than distinct builds, and none has had its
build string confirmed, so they are listed separately rather than given table rows.

| Vehicle | Platform | Notes |
|---|---|---|
| Official Xbox Magazine #57, May 2006 | Xbox / Xbox 360 | Cover-mounted demo disc. Also carried demos for Dreamfall: The Longest Journey, Over the Hedge and Marc Ecko's Getting Up. Relationship to the `IM-32983` demo above is unconfirmed. |
| Official PlayStation 2 Magazine Demo Disc 72 | PS2 | **Resolved into the table above** as build `22981`. The Europe disc (`SCED_54044`) carries a playable Hitman: Blood Money demo alongside 24: The Game, Black, Driver: Parallel Lines, We Love Katamari, Outrun 2006: Coast 2 Coast, TOCA Race Driver 3, Sonic Riders and Tomb Raider: Legend, with Rogue Galaxy as video only, matching the published UK contents list exactly. France (`SCED_54144`) carries the same executable. Germany (`SCED_54051`) carries no Hitman content. |
| *Hitman: Blood Money / Urban Chaos: Riot Response* | PS2 | A combined Eidos demo disc, catalogued by Redump as disc 58126. Details unverified; redump.org was unreachable at the time of writing. |
| Bonus Demo disc | PS2 | Packaged with some retail copies. Catalogued by Redump as disc 50413. Unverified. |
| PC downloadable demo | PC | Single mission, *Death of a Showman*, the abandoned amusement park. Mirrored on the Internet Archive. Presumed to be the `26039` build but not confirmed. |

Confirming any of these against the `IM-32983`, `SLUS-29191` or `26039` entries would be a
worthwhile addition.

An earlier revision of this page listed *Official U.S. PlayStation Magazine* demo disc #105 here.
That was wrong. Disc 105 is the June 2006 US disc and its contents do not include Hitman: Blood
Money; the entry came from a marketplace listing whose title paired the magazine issue with the
game without the disc carrying a demo of it. The UK disc above is the magazine demo that is
actually attested.

---

## Recovering exact build timestamps

The build string encodes a **date only**. No time of day appears anywhere in it. Exact
timestamps, where needed, have to come from the shipped binary or disc rather than the string,
using the following fields:

| Platform             | Source of exact timestamp                              |
|----------------------|--------------------------------------------------------|
| Xbox / Xbox 360 disc | XDVDFS volume descriptor FILETIME, at offset `0x10000`  |
| Xbox executable      | XBE image header timestamp field                        |
| Xbox 360 executable  | XEX optional header `0x00018002` (checksum/timestamp)   |
| PC executable        | PE COFF header `TimeDateStamp`                          |
| PS2 disc             | ISO 9660 Primary Volume Descriptor creation field       |

Two caveats when using these:

- A disc timestamp records when the disc was **mastered**, which is later than when the
  executable was built. Where both are available, prefer the executable timestamp.
- An executable timestamp records when the code was **linked**, which may still be later than
  the source revision it was built from. Where a build string is available, it remains the better
  record of when the code was written.

Note also that an Xbox disc leaves its ISO 9660 Primary Volume Descriptor zeroed, so ordinary
ISO tooling will report no creation date at all. The XDVDFS descriptor is the one to read.

## Finding the build string in an Xbox 360 build

The string is stored in the executable, so on Xbox 360 it is not visible on the disc. Scanning a
disc image for it directly does not work: a byte scan of all 5,283,741,696 bytes of the review
image returns nothing, because the XEX basefile is compressed.

It has to be decompressed first. Once `default.xex` is converted back to its underlying PE image
(`hitman3.pe`, the original module name recorded in the XEX header), the string appears in plain
ASCII and can be found with an ordinary search for `-2006` or `build`.

Both timestamps corroborate the result independently. `blood-build-xenon-20060409-25691` gives a
build date of 2006-04-09, and the XEX header timestamp reads 2006-04-09 15:08:20 UTC. Where a
decompressed executable is available the build string is the better record, since it also carries
the revision.

---

## Sources

- [Hidden Palace: Hitman: Blood Money prototypes](https://hiddenpalace.org/Category:Hitman:_Blood_Money_prototypes)
  - [Jan 20, 2006 prototype (PS2)](https://hiddenpalace.org/Hitman:_Blood_Money_(Jan_20,_2006_prototype))
  - [Apr 11, 2006 prototype (Xbox 360)](https://hiddenpalace.org/Hitman:_Blood_Money_(Apr_11,_2006_prototype))
  - [Apr 12, 2006 prototype (Xbox 360)](https://hiddenpalace.org/Hitman:_Blood_Money_(Apr_12,_2006_prototype))
- [Redump: Hitman: Blood Money](http://redump.org/disc/490/)
- [Internet Archive: Hitman: Blood Money Demo (PC)](https://archive.org/details/HitmanBloodMoney_201403)
- [Centre for Computing History: PS2 Official Magazine UK Demo Disc 72, May 2006](https://www.computinghistory.org.uk/det/56226/Playstation-2-Official-Magazine-UK-Demo-Disc-72-May-2006)

The Xbox 360 build string, executable hashes, timestamps and content differences were measured
directly from copies of the two discs and from the decompressed executable, rather than taken
from a catalogue.
