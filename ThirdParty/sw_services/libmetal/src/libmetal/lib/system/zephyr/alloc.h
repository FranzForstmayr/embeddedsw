/*
 * Copyright (c) 2017, Linaro Limited. and Contributors. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of Linaro nor the names of its contributors may be used
 *    to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * @file	zephyr/alloc.h
 * @brief	zephyr libmetal memory allocattion definitions.
 */

#ifndef __METAL_ALLOC__H__
#error "Include metal/alloc.h instead of metal/zephyr/alloc.h"
#endif

#ifndef __METAL_ZEPHYR_ALLOC__H__
#define __METAL_ZEPHYR_ALLOC__H__

#include <kernel.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#if (CONFIG_HEAP_MEM_POOL_SIZE > 0)
static inline void *metal_allocate_memory(unsigned int size)
{
	return k_malloc(size);
}

static inline void metal_free_memory(void *ptr)
{
	k_free(ptr);
}
#else

void *metal_zephyr_allocate_memory(unsigned int size);
void metal_zephyr_free_memory(void *ptr);

static inline void *metal_allocate_memory(unsigned int size)
{
	return metal_zephyr_allocate_memory(size);
}

static inline void metal_free_memory(void *ptr)
{
	metal_zephyr_free_memory(ptr);
}
#endif /* CONFIG_HEAP_MEM_POOL_SIZE */


#ifdef __cplusplus
}
#endif

#endif /* __METAL_ZEPHYR_ALLOC__H__ */
