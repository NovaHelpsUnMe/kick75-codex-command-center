# Firmware snapshot

This directory contains the Kick75 ANSI VIA source for the Codex Command Center. The `v1.0.0` release remains the stable historical baseline. The current source matches the September 18, 2026 physically accepted keyboard build.

- Upstream: [BunnyHorseCat/NuphyQMK](https://github.com/BunnyHorseCat/NuphyQMK)
- Upstream revision: `9606f5a1fbc2cad0489f07eb336d4e317ee29ee4`
- Target: `nuphy/kick75/ansi:via`
- Stable binary name: `nuphy_kick75_ansi_via.bin`
- Stable binary SHA-256: `76be851d4081b369e2b0effea444061d51fe81f5c440f7a93189cc61b8c59c66`

## September 18 physical keyboard source

- `keymap.c` SHA-256: `78e16b44f5dc826ef1be36fbef962b42e3aef11f3d6f638dd02ee81b195e61ca`
- `rgb_matrix_user.inc` SHA-256: `a93384730b4006a1490cc3b3d74eea79c9915ab99af117aa1ba334975ebd90bc`
- Accepted binary SHA-256: `fabe8ab1263de919295382f6fe260dac8c48de1ea18c318dbcbeea95a7a7ec64`
- Source provenance: `nuphy-kick75-codex-mode` commit `8371e2a90ac09aec81ca3f2b57d8763580e66c64`, with the live-build F6, F8, and F11 mappings and the Codex-mode Delete-position Govee toggle.

Build against the upstream revision above. Copy both source files to `keyboards/nuphy/kick75/ansi/keymaps/via/` in that QMK checkout, then run:

```bash
qmk compile -kb nuphy/kick75/ansi -km via -e SKIP_GIT=yes
```

The toggle sends Control-Option-Command-F18 only from the physical Delete-position key while Codex mode is active. Outside Codex mode, Delete and Fn+Insert retain their normal behavior. The Govee Edge Sync app must be running and have its keyboard toggle ready for the shortcut to control screen sync.

On September 24, 2026, both repository source files were copied into the QMK checkout at the upstream revision above and `gmake -j8 nuphy/kick75/ansi:via SKIP_GIT=yes` completed successfully. The newly built `.build/nuphy_kick75_ansi_via.bin` was 72,860 bytes with SHA-256 `6c40d8310cfdce02139de765cf2fff753d59ef0f6fd54474ab5fe869b2c0c3b9`. It did **not** match the September 18 flashed binary byte for byte. Source identity and a successful rebuild are verified; byte-identical reproduction and fresh physical behavior of the rebuilt binary are not verified. The September 18 physical acceptance remains supported by the recorded flash checksum and user test, not by a new flash.

The stable v1.0 binary is distributed through the GitHub Release rather than committed to Git. The September 18 binary is documented by its checksum above and can be rebuilt from these source files. See the [recovery guide](../docs/recovery.md).
