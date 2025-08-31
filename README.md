<div align="center">

  <h1>6502 assembly language server</h1>
  <img width="180" height="180" alt="6502_LS" src="https://github.com/user-attachments/assets/ef3e9679-fddf-4a9a-a184-3142e8bafd80" />

  <h3> !!!!!!! ⚠️  Work in progress ⚠️ !!!!!!! </h3>
  <h6> ---> Langauge server for 6502 assembly <--- </h6>

![C++](https://img.shields.io/badge/C++-blue?style=for-the-badge&logo=c%2B%2B)
![Work In Progress](https://img.shields.io/badge/Work%20In%20Progress-orange?style=for-the-badge)

</div>

## Disclaimer ##

> ⚠️ **Disclaimer:**  
> This project is currently **under heavy restructuring**.  
> The codebase may be broken or unstable during this transition phase.  
> Expect incomplete functionality, failing builds, and temporary inconsistencies.

## DEMO ## 

#### Completions ####

[![asciicast](https://asciinema.org/a/Vpxr4wl0QqZ83fRqBJO7xGunM.svg)](https://asciinema.org/a/Vpxr4wl0QqZ83fRqBJO7xGunM)

### Hover #### 
[![asciicast](https://asciinema.org/a/syKCKR74Qze1xiQ46AxoEDiyv.svg)](https://asciinema.org/a/syKCKR74Qze1xiQ46AxoEDiyv)

## Project structure ##

```bash

6502LS/
├── 6502ls-algo/
├── 6502ls-capabilities/
├── 6502ls-codeaction/
├── 6502ls-common/
├── 6502ls-completion/
├── 6502ls-config/
├── 6502ls-configuration-files/
├── 6502ls-core/
├── 6502ls-definition/
├── 6502ls-diagnostics/
├── 6502ls-enums/
├── 6502ls-errors/
├── 6502ls-hover/
├── 6502ls-instructions/
├── 6502ls-logging/
├── 6502ls-managers/
├── 6502ls-messages/
├── 6502ls-params/
├── 6502ls-repo/
├── 6502ls-results/
├── 6502ls-rpc/
├── 6502ls-scripts/
├── 6502ls-snippets/
├── 6502ls-test-files/
├── 6502ls-tests/
├── 6502ls-types/
├── 6502ls-utils/
├── CMakeLists.txt
├── Doxyfile
├── LICENSE
└── README.md


```

## Documentation ##
https://jkeresman01.github.io/6502_LS/

## Build ##

``` shell
cd 6502_LS
mkdir build && cd build
cmake ..
make -j$(nproc)
```


