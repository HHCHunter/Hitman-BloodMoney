# Releases & Builds

A catalogue of every known release of *Hitman: Blood Money*, with its engine build string decoded.

- [Reading a build string](#reading-a-build-string)
- [Retail releases](#retail-releases)
- [Retail demos](#retail-demos)
- [Pre-releases](#pre-releases)
- [Build timeline](#build-timeline)
- [Recovering exact build timestamps](#recovering-exact-build-timestamps)

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

The `BUILD DATE` and `REV` columns in the tables below are decoded directly from this field. They
are not estimates. Each one is a literal reading of the string on that row.

### Prefix variants

The leading portion varies by platform and build machine, but the trailing
`-<YYYYMMDD>-<revision>` is universal.

| Prefix form           | Seen on                                          |
|-----------------------|--------------------------------------------------|
| `blood-build3-`       | PC, PS2                                          |
| `blood-build4-`       | PC, PS2                                          |
| `blood-build-ps2-`    | PS2 pre-release                                  |
| `blood-build-xenon-`  | Xbox 360 (*Xenon* was the Xbox 360 dev codename) |
| `xbox-bloodbuild-`    | Original Xbox retail                             |
| `toolsbuild-`         | Xbox demo, built on the tools machine            |

### `build3` / `build4` is not a version number

It is tempting to read `build4` as "newer than `build3`". It is not. The data contradicts it in
two places:

- `25595` (`build3`) and `25599` (`build4`) were produced on the **same day**, 2006-04-03.
- `build4`/`25990` (PC 1.0, 2006-05-08) **precedes** `build3`/`26039` (PC demo, 2006-05-17).

The number identifies the build configuration or machine, not a sequence. Order builds by the
`REV` column instead.

### The revision counter is global

The trailing counter is shared by every platform rather than being per-platform. Sorting all
known builds by revision produces exactly the same order as sorting them by date (see
[Build timeline](#build-timeline)), with no crossovers between PC, PS2, Xbox or Xenon.

That means revision numbers are **directly comparable across platforms**: build `25827` (Xenon)
genuinely is later work than build `25599` (PS2), not merely a higher number on a different
counter.

Across the known range the counter advances from `21662` (2006-01-12) to `26152` (2006-07-13):
4,490 revisions over 182 days, averaging roughly 25 per day. That average can suggest an
approximate date for a build string not listed here, but treat it as an estimate only. Commit
rates are never uniform, and the decode of the date field itself is exact and needs no such
inference.

---

## Retail releases

| PLATFORM | VERSION | Release Type / Vendor   | Build String                     | BUILD DATE | REV   | REGION | TITLE ID   |
|----------|---------|-------------------------|----------------------------------|------------|-------|--------|------------|
| PC       | 1.2     | DIGITAL / GOG           | blood-build3-20060616-26123      | 2006-06-16 | 26123 |        |            |
| PC       | 1.2     | DIGITAL / STEAM         | blood-build3-20060601-26089      | 2006-06-01 | 26089 |        |            |
| PC       | 1.2     | PHYSICAL RETAIL RELEASE | blood-build3-20060616-26123      | 2006-06-16 | 26123 | UK     |            |
| PC       | 1.0     | PHYSICAL RETAIL RELEASE | blood-build4-20060508-25990      | 2006-05-08 | 25990 | USA    |            |
| PC       | 1.0     | PHYSICAL RETAIL RELEASE | blood-build4-20060508-25990      | 2006-05-08 | 25990 | USA    | [^dup]     |
| PC       | 1.?     | ?                       | blood-build3-20060713-26152      | 2006-07-13 | 26152 | RUS    |            |
| XBOX     |         | PHYSICAL RETAIL RELEASE | xbox-bloodbuild-20060317-25332   | 2006-03-17 | 25332 | AUS    | 534300FA   |
| Xbox 360 | 0.0.0.9 | DIGITAL / Xbox Live     | blood-build-xenon-20060422-25827 | 2006-04-22 | 25827 | USA    | 534307DB   |
| PS2      | 1.01    | PHYSICAL RETAIL RELEASE | blood-build3-20060403-25595      | 2006-04-03 | 25595 | USA    | SLUS-21108 |
| PS2      | 2.00    | PHYSICAL RETAIL RELEASE | blood-build3-20060403-25595      | 2006-04-03 | 25595 | EUR    | SLES-53028 |
| PS2      | 1.00    | PHYSICAL RETAIL RELEASE | blood-build4-20060403-25599      | 2006-04-03 | 25599 | FRA    | SLES-53029 |
| PS2      | 1.00    | PHYSICAL RETAIL RELEASE | blood-build4-20060403-25599      | 2006-04-03 | 25599 | GER    | SLES-53030 |
| PS2      | 1.00    | PHYSICAL RETAIL RELEASE | blood-build4-20060403-25599      | 2006-04-03 | 25599 | ITA    | SLES-53031 |
| PS2      | 1.00    | PHYSICAL RETAIL RELEASE | blood-build4-20060403-25599      | 2006-04-03 | 25599 | SPA    | SLES-53032 |
| PS3      |         | PHYSICAL RETAIL RELEASE | *unknown*                        | n/a        | n/a   | USA    | BLUS30942  |

[^dup]: This row duplicates the one above it verbatim in the source data. Retained rather than
deleted in case the two entries were meant to record distinct printings that were never
differentiated. Needs confirmation against physical media.

**PS3**: no build string has been recorded for this release, so no date can be decoded.

## Retail demos

| PLATFORM | VERSION | Release Type / Vendor | Build String                | BUILD DATE | REV   | REGION | TITLE ID   |
|----------|---------|-----------------------|-----------------------------|------------|-------|--------|------------|
| PC       |         | DEMO                  | blood-build3-20060517-26039 | 2006-05-17 | 26039 |        |            |
| XBOX     |         | DEMO                  | toolsbuild-20060112-21662   | 2006-01-12 | 21662 | USA    | IM-32983   |
| PS2      | 1.00    | DEMO                  | blood-build3-20060124-22440 | 2006-01-24 | 22440 | USA    | SLUS-29191 |

The Xbox demo is the **earliest known build of the game**, at revision `21662`, over three months
before the first Xbox retail build. It is also the only known build produced on the `toolsbuild`
machine.

## Pre-releases

| PLATFORM | VERSION | Release Type / Vendor | Build String                   | BUILD DATE | REV   | REGION | TITLE ID           |
|----------|---------|-----------------------|--------------------------------|------------|-------|--------|--------------------|
| PS2      | 0.5     | BETA                  | blood-build-ps2-20060118-21982 | 2006-01-18 | 21982 | USA    | SLES-53028[^ps2id] |
| Xbox 360 |         | REVIEW                | *unconfirmed*[^review]         | 2006-04-09 | n/a   |        | none assigned      |

[^ps2id]: This title ID duplicates the PS2 EUR retail entry (`SLES-53028`), while the row is
marked region USA. One of the two is likely mistaken, or the beta was pressed using the EUR
retail ID before a dedicated one was assigned. Recorded as found, not corrected.

[^review]: See [The Xbox 360 review build](#the-xbox-360-review-build) below for the full
derivation. The `BUILD DATE` given is the executable link timestamp, not a decoded build string.

### The Xbox 360 review build

Identified from a disc image. The disc is XDVDFS, with the `MICROSOFT*XBOX*MEDIA` signature at
offset `0x10000` and its root directory at sector 1343432.

It is an **Xbox 360** disc, not an original Xbox one. XDVDFS is used by both consoles, so the
filesystem alone does not settle it, but the contents do:

- the executable is `default.xex` (XEX2 format, Xbox 360) rather than `default.xbe` (Xbox)
- the audio streams are named `XBox2_Eng.s01` through `.s09` plus `XBox2_Eng.str`, *Xbox 2*
  being the pre-release name for the Xbox 360
- a `$SystemUpdate` directory is present, which is an Xbox 360 disc convention

Two independent timestamps were recovered:

| Source                                     | Timestamp               |
|--------------------------------------------|-------------------------|
| `default.xex` XEX header checksum/timestamp | 2006-04-09 15:08:20 UTC |
| XDVDFS volume descriptor FILETIME           | 2006-04-12 08:00:15 UTC |

The three-day gap is the expected shape: the executable is linked first, and the disc is mastered
afterwards. The link timestamp is the better record of when the code was built, so it is the one
used in the table above.

Other details from the XEX header:

- original PE name `hitman3.pe`, confirming the internal project name (Blood Money was the third
  Hitman title)
- execution info title ID `0x00000000`, i.e. **no title ID assigned**, consistent with a
  pre-release. The retail Xbox 360 release carries `534307DB`.

**The build string could not be recovered.** A full byte scan of all 5,283,741,696 bytes of the
disc image found no plaintext build string matching any known prefix. The string is inside the
XEX basefile, which is compressed, so recovering it requires decompressing the executable rather
than searching for it.

By its link date this is the **earliest known Xbox 360 build**, 13 days before the retail Xenon
build of 2006-04-22.

---

## Build timeline

Every known build, ordered by revision. The order is identical whether sorted by revision or by
date, which is what establishes that the counter is global.

| REV   | BUILD DATE | PLATFORM | Release                          |
|-------|------------|----------|----------------------------------|
| 21662 | 2006-01-12 | XBOX     | Demo                             |
| 21982 | 2006-01-18 | PS2      | Beta 0.5                         |
| 22440 | 2006-01-24 | PS2      | Demo                             |
| 25332 | 2006-03-17 | XBOX     | Retail, AUS                      |
| 25595 | 2006-04-03 | PS2      | Retail, USA and EUR              |
| 25599 | 2006-04-03 | PS2      | Retail, FRA, GER, ITA, SPA       |
| n/a   | 2006-04-09 | Xbox 360 | Review build *(from disc)*       |
| 25827 | 2006-04-22 | Xbox 360 | Xbox Live release                |
| 25990 | 2006-05-08 | PC       | Retail 1.0, USA                  |
| 26039 | 2006-05-17 | PC       | Demo                             |
| 26089 | 2006-06-01 | PC       | Retail 1.2, Steam                |
| 26123 | 2006-06-16 | PC       | Retail 1.2, GOG and UK physical  |
| 26152 | 2006-07-13 | PC       | Retail 1.? RUS                   |

> The Xbox 360 review build is placed by its executable link timestamp and has no known revision,
> so it sits outside the revision ordering. Every row that *does* have a revision is in strict
> order on both columns.

Reading the timeline: console versions were finished first, with all PS2 and Xbox retail builds
done by 2006-04-22, while the PC version continued for a further three months. The RUS release
was built almost two months after the PC version otherwise shipped.

---

## Recovering exact build timestamps

The build string encodes a **date only**. No time of day appears anywhere in it. Exact
timestamps, where needed, have to come from the shipped binary or disc rather than the string,
using the following fields:

| Platform             | Source of exact timestamp                             |
|----------------------|-------------------------------------------------------|
| Xbox / Xbox 360 disc | XDVDFS volume descriptor FILETIME, at offset `0x10000` |
| Xbox executable      | XBE image header timestamp field                       |
| Xbox 360 executable  | XEX optional header `0x00018002` (checksum/timestamp)  |
| PC executable        | PE COFF header `TimeDateStamp`                         |
| PS2 disc             | ISO 9660 Primary Volume Descriptor creation field      |

Only the Xbox 360 review build above currently has timestamps recorded this way. As further
artifacts are examined, results can be added as an extra column beside `BUILD DATE`.

Two caveats when using these:

- A disc timestamp records when the disc was **mastered**, which is later than when the
  executable was built. Where both are available, prefer the executable timestamp.
- An executable timestamp records when the code was **linked**, which may still be later than
  the source revision it was built from. Where a build string is available, it remains the better
  record of when the code was written.

Note also that an Xbox disc leaves its ISO 9660 Primary Volume Descriptor zeroed, so ordinary
ISO tooling will report no creation date at all. The XDVDFS descriptor is the one to read.
