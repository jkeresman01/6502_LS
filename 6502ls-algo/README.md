# 6502ls-algo

This module provides basic algorithmic structures used across the 6502 Language Server.

## Structure

- `Trie` — Core prefix-tree implementation
- `Node` — Trie node helper

## Usage

```cpp
#include "Trie.h"

Trie trie;
trie.insert("LDA");

