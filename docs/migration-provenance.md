# Migration provenance

This repository was created by filtering the Codex Command Center history from the original mixed repository. Filtering rewrites commit trees, so filtered-history commit identifiers differ from the original repository even when retained file contents are unchanged.

## Provenance anchor

- Source repository: `NovaHelpsUnMe/kick75-customizer-app`
- Source branch: `main`
- Original source commit: `563951373474171982c6d32f70fb8b518febc6fe`
- Original stable release: `v1.0.0`
- Recorded upstream QMK repository: `BunnyHorseCat/NuphyQMK`
- Recorded upstream QMK revision: `9606f5a1fbc2cad0489f07eb336d4e317ee29ee4`
- Firmware target: `nuphy/kick75/ansi:via`
- Stable firmware asset: `nuphy_kick75_ansi_via.bin`
- Stable firmware SHA-256: `76be851d4081b369e2b0effea444061d51fe81f5c440f7a93189cc61b8c59c66`

The original source commit remains the authoritative provenance anchor. The destination `v1.0.0` tag identifies the corresponding filtered history in this repository. The release assets were retrieved from the original historical release and migrated without rebuilding or replacing them.

## Repository boundary

This repository owns the Kick75 Codex QMK firmware, Codex and reasoning layers, RGB task statuses, KITT behavior, Raw HID integration, macOS Status and Sidebar helpers, state parser and tests, firmware recovery, helper builds, release artifacts, and future keyboard-side work.

The separate `NovaHelpsUnMe/kick75-customizer-app` repository owns VIA definition tooling, profile parsing and import/export, keyboard visualization, the customizer UI, and customizer tests.
