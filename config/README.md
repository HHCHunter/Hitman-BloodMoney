# Configuration Files

Formatted, documented and commented hand-written configuration files for *Hitman: Blood Money*.
Both files shipped with no documentation; these copies carry per-setting comments inline.

| File | Purpose |
|---|---|
| [`HitmanBloodMoney.ini`](HitmanBloodMoney.ini) | Engine configuration — graphics, audio, gameplay, scripting, debug. Also referred to as `MAIN.ini`. |
| [`HM3GPAD.cfg`](HM3GPAD.cfg) | Controller and keyboard bindings, including the debug and cheat keys. |

📖 **[Full configuration reference →](../docs/config-reference.md)** — every section explained,
plus the binding expression syntax used by `HM3GPAD.cfg`.

## What these are configured for

The provided `HitmanBloodMoney.ini` is written for one specific scenario:

- **4K resolution** (`3840x2160`), 8×AA, 16× anisotropic filtering, maximum texture and shadow detail
- **Debug options enabled** — console, cheats, debug key bindings and on-screen debug output

It is meant to be re-configured to taste rather than used as-is. Every setting is commented in
place, so lowering the resolution or turning the debug output off is a matter of editing the
relevant line.

## Installing

Both files belong in the game's root directory, alongside the executable — the same folder that
contains `Scenes/`. The engine reads `HitmanBloodMoney.ini` at startup, and the `ConfigFile`
setting inside it points at `HM3GPAD.cfg`.

**Back up your originals first.** These files replace the ones the game shipped with.

## Two things worth knowing before you edit

- Setting `ReadMainIni 1` makes the engine use the executable's **pre-baked** configuration and
  ignore this file completely. Leave it at `0`.
- Uncommenting `BuildTag` **freezes the game on boot**.

Debug bindings in the `DebugKeys` block of `HM3GPAD.cfg` do not work on retail builds — see
[Enabling the debug features](../docs/config-reference.md#enabling-the-debug-features) for the
workaround.
