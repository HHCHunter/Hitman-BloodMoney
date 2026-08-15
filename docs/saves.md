# Save Files

Notes on the save-game format used by *Hitman: Blood Money*.

> **Status: research in progress.** This page is a placeholder — the format has not been
> documented here yet.

## Scope

On PC, save data lives in the user's `Documents\Hitman Blood Money\Profiles\<PROFILE>\` directory
rather than in the game folder. A profile there consists of:

| File | Notes |
|---|---|
| `Profile.pro` | Profile data — progression and unlocks. |
| `SaveGame#N.control` | Save slot control/header data. |
| `SaveGame#N.data` | Save slot payload. |
| `SaveInfo` | Slot index. |
| `Settings.dat` | Per-profile settings. |

The `#N` suffix increments per save slot.

## Open questions

- Container structure of the `.control` / `.data` pair, and how the two relate.
- Whether any checksum or integrity field is present.
- Whether the format is shared with the console releases, or PC-specific.
- What is stored in `Profile.pro` versus the individual save slots.

Contributions welcome — see [releases.md](releases.md) for the build catalogue, since save format
differences are most likely to track platform and build.
