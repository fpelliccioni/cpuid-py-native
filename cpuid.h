/*===---- cpuid.h - X86 cpu model detection --------------------------------===
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 *===-----------------------------------------------------------------------===
 */

#if !(__x86_64__ || __i386__ || _WIN32)
#error this header is for x86 only
#endif

#include <stdint.h>

#ifdef _WIN32
#include <intrin.h>
#endif // _WIN32

/* Responses identification request with %eax 0 */
/* AMD:     "AuthenticAMD" */
#define signature_AMD_ebx 0x68747541
#define signature_AMD_edx 0x69746e65
#define signature_AMD_ecx 0x444d4163
/* CENTAUR: "CentaurHauls" */
#define signature_CENTAUR_ebx 0x746e6543
#define signature_CENTAUR_edx 0x48727561
#define signature_CENTAUR_ecx 0x736c7561
/* CYRIX:   "CyrixInstead" */
#define signature_CYRIX_ebx 0x69727943
#define signature_CYRIX_edx 0x736e4978
#define signature_CYRIX_ecx 0x64616574
/* INTEL:   "GenuineIntel" */
#define signature_INTEL_ebx 0x756e6547
#define signature_INTEL_edx 0x49656e69
#define signature_INTEL_ecx 0x6c65746e
/* TM1:     "TransmetaCPU" */
#define signature_TM1_ebx 0x6e617254
#define signature_TM1_edx 0x74656d73
#define signature_TM1_ecx 0x55504361
/* TM2:     "GenuineTMx86" */
#define signature_TM2_ebx 0x756e6547
#define signature_TM2_edx 0x54656e69
#define signature_TM2_ecx 0x3638784d
/* NSC:     "Geode by NSC" */
#define signature_NSC_ebx 0x646f6547
#define signature_NSC_edx 0x43534e20
#define signature_NSC_ecx 0x79622065
/* NEXGEN:  "NexGenDriven" */
#define signature_NEXGEN_ebx 0x4778654e
#define signature_NEXGEN_edx 0x72446e65
#define signature_NEXGEN_ecx 0x6e657669
/* RISE:    "RiseRiseRise" */
#define signature_RISE_ebx 0x65736952
#define signature_RISE_edx 0x65736952
#define signature_RISE_ecx 0x65736952
/* SIS:     "SiS SiS SiS " */
#define signature_SIS_ebx 0x20536953
#define signature_SIS_edx 0x20536953
#define signature_SIS_ecx 0x20536953
/* UMC:     "UMC UMC UMC " */
#define signature_UMC_ebx 0x20434d55
#define signature_UMC_edx 0x20434d55
#define signature_UMC_ecx 0x20434d55
/* VIA:     "VIA VIA VIA " */
#define signature_VIA_ebx 0x20414956
#define signature_VIA_edx 0x20414956
#define signature_VIA_ecx 0x20414956
/* VORTEX:  "Vortex86 SoC" */
#define signature_VORTEX_ebx 0x74726f56
#define signature_VORTEX_edx 0x36387865
#define signature_VORTEX_ecx 0x436f5320

/* Features in %ecx for leaf 1 */
#define bit_SSE3        0x00000001
#define bit_PCLMULQDQ   0x00000002
#define bit_PCLMUL      bit_PCLMULQDQ   /* for gcc compat */
#define bit_DTES64      0x00000004
#define bit_MONITOR     0x00000008
#define bit_DSCPL       0x00000010
#define bit_VMX         0x00000020
#define bit_SMX         0x00000040
#define bit_EIST        0x00000080
#define bit_TM2         0x00000100
#define bit_SSSE3       0x00000200
#define bit_CNXTID      0x00000400
#define bit_FMA         0x00001000
#define bit_CMPXCHG16B  0x00002000
#define bit_xTPR        0x00004000
#define bit_PDCM        0x00008000
#define bit_PCID        0x00020000
#define bit_DCA         0x00040000
#define bit_SSE41       0x00080000
#define bit_SSE4_1      bit_SSE41       /* for gcc compat */
#define bit_SSE42       0x00100000
#define bit_SSE4_2      bit_SSE42       /* for gcc compat */
#define bit_x2APIC      0x00200000
#define bit_MOVBE       0x00400000
#define bit_POPCNT      0x00800000
#define bit_TSCDeadline 0x01000000
#define bit_AESNI       0x02000000
#define bit_AES         bit_AESNI       /* for gcc compat */
#define bit_XSAVE       0x04000000
#define bit_OSXSAVE     0x08000000
#define bit_AVX         0x10000000
#define bit_F16C        0x20000000
#define bit_RDRND       0x40000000

/* Features in %edx for leaf 1 */
#define bit_FPU         0x00000001
#define bit_VME         0x00000002
#define bit_DE          0x00000004
#define bit_PSE         0x00000008
#define bit_TSC         0x00000010
#define bit_MSR         0x00000020
#define bit_PAE         0x00000040
#define bit_MCE         0x00000080
#define bit_CX8         0x00000100
#define bit_CMPXCHG8B   bit_CX8         /* for gcc compat */
#define bit_APIC        0x00000200
#define bit_SEP         0x00000800
#define bit_MTRR        0x00001000
#define bit_PGE         0x00002000
#define bit_MCA         0x00004000
#define bit_CMOV        0x00008000
#define bit_PAT         0x00010000
#define bit_PSE36       0x00020000
#define bit_PSN         0x00040000
#define bit_CLFSH       0x00080000
#define bit_DS          0x00200000
#define bit_ACPI        0x00400000
#define bit_MMX         0x00800000
#define bit_FXSR        0x01000000
#define bit_FXSAVE      bit_FXSR        /* for gcc compat */
#define bit_SSE         0x02000000
#define bit_SSE2        0x04000000
#define bit_SS          0x08000000
#define bit_HTT         0x10000000
#define bit_TM          0x20000000
#define bit_PBE         0x80000000

/* Features in %ebx for leaf 7 sub-leaf 0 */
#define bit_FSGSBASE    0x00000001
#define bit_SGX         0x00000004
#define bit_BMI         0x00000008
#define bit_HLE         0x00000010
#define bit_AVX2        0x00000020
#define bit_SMEP        0x00000080
#define bit_BMI2        0x00000100
#define bit_ENH_MOVSB   0x00000200
#define bit_RTM         0x00000800
#define bit_MPX         0x00004000
#define bit_AVX512F     0x00010000
#define bit_AVX512DQ    0x00020000
#define bit_RDSEED      0x00040000
#define bit_ADX         0x00080000
#define bit_AVX512IFMA  0x00200000
#define bit_CLFLUSHOPT  0x00800000
#define bit_CLWB        0x01000000
#define bit_AVX512PF    0x04000000
#define bit_AVX51SER    0x08000000
#define bit_AVX512CD    0x10000000
#define bit_SHA         0x20000000
#define bit_AVX512BW    0x40000000
#define bit_AVX512VL    0x80000000

/* Features in %ecx for leaf 7 sub-leaf 0 */
#define bit_PREFTCHWT1  0x00000001
#define bit_AVX512VBMI  0x00000002
#define bit_PKU         0x00000004
#define bit_OSPKE       0x00000010
#define bit_AVX512VPOPCNTDQ  0x00004000
#define bit_RDPID       0x00400000

/* Features in %edx for leaf 7 sub-leaf 0 */
#define bit_AVX5124VNNIW  0x00000004
#define bit_AVX5124FMAPS  0x00000008

/* Features in %eax for leaf 13 sub-leaf 1 */
#define bit_XSAVEOPT    0x00000001
#define bit_XSAVEC      0x00000002
#define bit_XSAVES      0x00000008

/* Features in %ecx for leaf 0x80000001 */
#define bit_LAHF_LM     0x00000001
#define bit_ABM         0x00000020
#define bit_SSE4a       0x00000040
#define bit_PRFCHW      0x00000100
#define bit_XOP         0x00000800
#define bit_LWP         0x00008000
#define bit_FMA4        0x00010000
#define bit_TBM         0x00200000
#define bit_MWAITX      0x20000000

/* Features in %edx for leaf 0x80000001 */
#define bit_MMXEXT      0x00400000
#define bit_LM          0x20000000
#define bit_3DNOWP      0x40000000
#define bit_3DNOW       0x80000000

/* Features in %ebx for leaf 0x80000001 */
#define bit_CLZERO      0x00000001


#ifndef _WIN32
#if __i386__
#define __cpuid(__leaf, __eax, __ebx, __ecx, __edx) \
    __asm("cpuid" : "=a"(__eax), "=b" (__ebx), "=c"(__ecx), "=d"(__edx) \
                  : "0"(__leaf))

#define __cpuid_count(__leaf, __count, __eax, __ebx, __ecx, __edx) \
    __asm("cpuid" : "=a"(__eax), "=b" (__ebx), "=c"(__ecx), "=d"(__edx) \
                  : "0"(__leaf), "2"(__count))
#else // __i386__
/* x86-64 uses %rbx as the base register, so preserve it. */
#define __cpuid(__leaf, __eax, __ebx, __ecx, __edx) \
    __asm("  xchgq  %%rbx,%q1\n" \
          "  cpuid\n" \
          "  xchgq  %%rbx,%q1" \
        : "=a"(__eax), "=r" (__ebx), "=c"(__ecx), "=d"(__edx) \
        : "0"(__leaf))

#define __cpuid_count(__leaf, __count, __eax, __ebx, __ecx, __edx) \
    __asm("  xchgq  %%rbx,%q1\n" \
          "  cpuid\n" \
          "  xchgq  %%rbx,%q1" \
        : "=a"(__eax), "=r" (__ebx), "=c"(__ecx), "=d"(__edx) \
        : "0"(__leaf), "2"(__count))
#endif // __i386__
#else // _WIN32

static __inline 
void __cpuid(unsigned int __leaf, unsigned int* __eax, unsigned int* __ebx, unsigned int* __ecx, unsigned int* __edx) {
    int cpui[4];  
    __cpuid(cpui, __leaf);
    *__eax = cpui[0];
    *__ebx = cpui[1];
    *__ecx = cpui[2];
    *__edx = cpui[3];
}

static __inline 
void __cpuid_count(unsigned int __leaf, unsigned int __count, unsigned int* __eax, unsigned int* __ebx, unsigned int* __ecx, unsigned int* __edx) {
    int cpui[4];  
    __cpuidex(cpui, __leaf, __count);  
    *__eax = cpui[0];
    *__ebx = cpui[1];
    *__ecx = cpui[2];
    *__edx = cpui[3];
}

#endif // _WIN32


static __inline 
void cpuid(unsigned int leaf, unsigned int* eax, unsigned int* ebx, unsigned int* ecx, unsigned int* edx) {
#ifndef _WIN32
    __cpuid(leaf, *eax, *ebx, *ecx, *edx);
#else // _WIN32
    __cpuid(leaf, eax, ebx, ecx, edx);
#endif // _WIN32
}

static __inline 
void cpuid_count(unsigned int leaf, unsigned int count, unsigned int* eax, unsigned int* ebx, unsigned int* ecx, unsigned int* edx) {
#ifndef _WIN32
    __cpuid_count(leaf, count, *eax, *ebx, *ecx, *edx);
#else // _WIN32
    __cpuid_count(leaf, count, eax, ebx, ecx, edx);
#endif // _WIN32
}

static __inline 
int __get_cpuid_max (unsigned int __leaf, unsigned int *__sig) {
    unsigned int __eax, __ebx, __ecx, __edx;

#ifndef _WIN32
#if __i386__
    int __cpuid_supported;

    __asm("  pushfl\n"
          "  popl   %%eax\n"
          "  movl   %%eax,%%ecx\n"
          "  xorl   $0x00200000,%%eax\n"
          "  pushl  %%eax\n"
          "  popfl\n"
          "  pushfl\n"
          "  popl   %%eax\n"
          "  movl   $0,%0\n"
          "  cmpl   %%eax,%%ecx\n"
          "  je     1f\n"
          "  movl   $1,%0\n"
          "1:"
        : "=r" (__cpuid_supported) : : "eax", "ecx");
    if (!__cpuid_supported)
        return 0;
#endif // __i386__
#endif // _WIN32

    cpuid(__leaf, &__eax, &__ebx, &__ecx, &__edx);
    if (__sig)
        *__sig = __ebx;
    return __eax;
}



static __inline 
int __get_cpuid (unsigned int __leaf, unsigned int *__eax,
                                 unsigned int *__ebx, unsigned int *__ecx,
                                 unsigned int *__edx) {
    unsigned int __max_leaf = __get_cpuid_max(__leaf & 0x80000000, 0);

    if (__max_leaf == 0 || __max_leaf < __leaf)
        return 0;

    cpuid(__leaf, __eax, __ebx, __ecx, __edx);
    return 1;
}

static __inline 
int __get_cpuid_count (unsigned int __leaf,
                                       unsigned int __subleaf,
                                       unsigned int *__eax, unsigned int *__ebx,
                                       unsigned int *__ecx, unsigned int *__edx) {
    unsigned int __max_leaf = __get_cpuid_max(__leaf & 0x80000000, 0);

    if (__max_leaf == 0 || __max_leaf < __leaf)
        return 0;

    cpuid_count(__leaf, __subleaf, __eax, __ebx, __ecx, __edx);
    return 1;
}



//Based on https://github.com/vectorclass/version2/blob/master/instrset_detect.cpp#L21
static __inline 
uint64_t xgetbv(int ctr) {	
#if (defined (_MSC_FULL_VER) && _MSC_FULL_VER >= 160040000) || (defined (__INTEL_COMPILER) && __INTEL_COMPILER >= 1200)
    // Microsoft or Intel compiler supporting _xgetbv intrinsic
    return uint64_t(_xgetbv(ctr));                    // intrinsic function for XGETBV

//TODO(fernando): apparently GCC8 supports the intrinsic.
#elif defined(__GNUC__) ||  defined (__clang__)       // use inline assembly, Gnu/AT&T syntax
   uint32_t a, d;
   __asm("xgetbv" : "=a"(a),"=d"(d) : "c"(ctr) : );
   return a | (uint64_t(d) << 32);
#else  // #elif defined (_WIN32)                      // other compiler. try inline assembly with masm/intel/MS syntax
   uint32_t a, d;
    __asm {
        mov ecx, ctr
        _emit 0x0f
        _emit 0x01
        _emit 0xd0 ; // xgetbv
        mov a, eax
        mov d, edx
    }
   return a | (uint64_t(d) << 32);
#endif
}

// https://docs.microsoft.com/en-us/cpp/intrinsics/rdtscp?view=vs-2019
// https://stackoverflow.com/questions/14783782/which-inline-assembly-code-is-correct-for-rdtscp/14783846#14783846
static __inline 
uint64_t rdtscp(unsigned int* aux) {
#if (defined (_MSC_FULL_VER) && _MSC_FULL_VER >= 160040000) || (defined (__INTEL_COMPILER) && __INTEL_COMPILER >= 1200)
    return __rdtscp(aux);
#elif defined(__GNUC__) ||  defined (__clang__)       // use inline assembly, Gnu/AT&T syntax
    uint64_t rax,rdx;
    asm volatile ( "rdtscp\n" : "=a" (rax), "=d" (rdx), "=c" (aux) : : );
    return (rdx << 32) + rax;
#endif
}
