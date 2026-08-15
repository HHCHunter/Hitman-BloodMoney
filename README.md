# Hitman: Blood Money

Tools, documentation and reference data for *Hitman: Blood Money* (IO Interactive, 2006) and its
Glacier engine — a catalogue of every known release with its build string decoded, documented
configuration files for a game that shipped with none, and the open-source tools published for it.

## Contents

| | |
|---|---|
| 📀 **[Releases & Builds](docs/releases.md)** | Every known release across PC, PS2, Xbox, Xbox 360 and PS3, with build strings decoded to dates and revisions. |
| ⚙️ **[Configuration Files](config/)** | Formatted, commented `HitmanBloodMoney.ini` and `HM3GPAD.cfg`. |
| 📖 **[Configuration Reference](docs/config-reference.md)** | What every setting does, and the binding syntax used by `HM3GPAD.cfg`. |
| 🛠️ **[Tools](tools/)** | Cheat enabler and PRM→OBJ model converter. |
| 💾 **[Save Files](docs/saves.md)** | Save format notes — research in progress. |

## Releases at a glance

The game was built from a single source tree with one shared revision counter across all
platforms, so builds can be ordered against each other regardless of platform. Console versions
were finished first — every PS2 and Xbox build was done by April 2006 — while PC development
continued into July.

| Platform | First known build | Last known build |
|---|---|---|
| Xbox | 2006-01-12 *(demo)* | 2006-03-17 *(retail)* |
| PS2 | 2006-01-18 *(beta)* | 2006-04-03 *(retail)* |
| Xbox 360 | — | 2006-04-22 |
| PC | 2006-05-08 *(retail 1.0)* | 2006-07-13 *(RUS)* |

Full tables, the build-string grammar and the decoding notes are in
**[docs/releases.md](docs/releases.md)**.

## Configuration

The [`config/`](config/) files are hand-written, fully commented versions of the two files the
engine reads at startup — files that shipped entirely undocumented. They are set up for 4K
resolution with debug options enabled, and are meant to be adapted rather than used verbatim.

Note that debug key bindings do not work on retail builds without
[a workaround](docs/config-reference.md#enabling-the-debug-features).

## Credits

The tools collected in [`tools/`](tools/) are the work of their original authors — **ZoID** and
**RDJ** (cheat enabler), and **John "Cryect" Rittenhouse** (PRM converter) — and are included
under their original terms. See [Third-party components](tools/README.md#third-party-components).

## Contributing

Corrections and additions are welcome, particularly:

- Build strings for releases not yet catalogued, especially the **PS3 release** and the **Xbox
  review build**, both of which are currently listed without one.
- Confirmation of the two flagged inconsistencies in the release tables.
- Anything on the [save file format](docs/saves.md).

## License

[MIT](LICENSE), covering the documentation and configuration files authored in this repository.
It does not extend to the third-party tools in [`tools/`](tools/), nor to any *Hitman: Blood
Money* game assets — this repository is unaffiliated with IO Interactive and Eidos.
