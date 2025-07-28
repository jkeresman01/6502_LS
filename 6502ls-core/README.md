# ls6502-core

Core components and logic for the 6502 Language Server.

## Structure

- `Ls6502Client` – Orchestrates interactions with the LSP client
- `Ls6502Facade` – High-level interface coordinating internal logic
- `Ls6502Server` – Main server engine
- `Ls6502ErrorHandler` – Handles and reports error conditions
- `Ls6502Counter` – Internal statistics or metrics counter
- `Ls6502ReqHandler` – Handles the standardizes LSP requests

## Usage

This library provides the core coordination logic used in the LSP backend.

