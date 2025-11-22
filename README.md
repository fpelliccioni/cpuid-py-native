# cpuid-native

[![PyPI version](https://badge.fury.io/py/cpuid-native.svg)](https://badge.fury.io/py/cpuid-native)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Python Support](https://img.shields.io/pypi/pyversions/cpuid-native.svg)](https://pypi.org/project/cpuid-native/)

**Native Python bindings for x86 CPUID instruction**

A lightweight C/C++ extension that provides direct, low-level access to x86/x64 processor identification and feature detection through the CPUID instruction.

## Features

- **Zero-dependency native extension** - Direct CPU instruction access with minimal overhead
- **Cross-platform support** - Works on Linux, macOS, and Windows
- **Wide Python compatibility** - Supports Python 3.7 through 3.13
- **Low-level control** - Direct access to CPUID leaves and subleaves
- **Extended instructions** - Support for XGETBV and RDTSCP

## Installation

```bash
pip install cpuid-native
```

## Quick Start

```python
import cpuid_native

# Get basic CPUID information (leaf 0)
success, eax, ebx, ecx, edx = cpuid_native.get_cpuid(0)
print(f"Max supported leaf: {eax}")

# Get CPU features (leaf 1)
success, eax, ebx, ecx, edx = cpuid_native.get_cpuid(1)
print(f"Family/Model/Stepping: {eax:08x}")

# Use count variant for extended leaves
success, eax, ebx, ecx, edx = cpuid_native.get_cpuid_count(7, 0)
print(f"Extended features: {ebx:08x}")

# Check XSAVE extended state
xcr0 = cpuid_native.xgetbv(0)
print(f"XCR0 register: {xcr0:016x}")

# Read timestamp counter
tsc, aux = cpuid_native.rdtscp()
print(f"TSC: {tsc}, AUX: {aux}")
```

## API Reference

### `get_cpuid(leaf)`

Execute CPUID instruction with the specified leaf.

**Parameters:**
- `leaf` (int): CPUID leaf number (EAX input)

**Returns:**
- Tuple of `(success, eax, ebx, ecx, edx)` where success is 1 if the leaf is supported

### `get_cpuid_count(leaf, subleaf)`

Execute CPUID instruction with leaf and subleaf.

**Parameters:**
- `leaf` (int): CPUID leaf number (EAX input)
- `subleaf` (int): CPUID subleaf number (ECX input)

**Returns:**
- Tuple of `(success, eax, ebx, ecx, edx)`

### `xgetbv(ctr)`

Execute XGETBV instruction to read extended control registers.

**Parameters:**
- `ctr` (int): Extended control register number (typically 0 for XCR0)

**Returns:**
- 64-bit value from the specified extended control register

### `rdtscp()`

Read time-stamp counter and processor ID.

**Returns:**
- Tuple of `(tsc, aux)` where tsc is the 64-bit timestamp counter and aux is the processor ID

## Use Cases

- **CPU feature detection** - Check for SSE, AVX, BMI instruction support
- **Performance optimization** - Select optimal code paths based on CPU capabilities
- **System diagnostics** - Low-level processor information gathering
- **Virtualization detection** - Identify hypervisor presence
- **Benchmarking** - Precise timing with RDTSCP

## For High-Level API

For a more Pythonic interface with automatic CPU identification and feature detection, see [cpuid](https://github.com/fpelliccioni/cpuid-py) which builds on top of this library.

## Building from Source

```bash
git clone https://github.com/fpelliccioni/cpuid-py-native.git
cd cpuid-py-native
pip install -e .
```

## License

MIT License - see [LICENSE](LICENSE) file for details.

## Credits

Created and maintained by [Fernando Pelliccioni](https://github.com/fpelliccioni)
