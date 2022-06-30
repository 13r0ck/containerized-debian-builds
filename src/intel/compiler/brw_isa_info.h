/*
 * Copyright © 2022 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * on the rights to use, copy, modify, merge, publish, distribute, sub
 * license, and/or sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHOR(S) AND/OR THEIR SUPPLIERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
 * USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef BRW_ISA_ENCODING_H
#define BRW_ISA_ENCODING_H

#include "dev/intel_device_info.h"
#include "brw_eu_defines.h"

#ifdef __cplusplus
extern "C" {
#endif

struct opcode_desc {
   unsigned ir;
   unsigned hw;
   const char *name;
   int nsrc;
   int ndst;
   int gfx_vers;
};

const struct opcode_desc *
brw_opcode_desc(const struct intel_device_info *devinfo, enum opcode opcode);

const struct opcode_desc *
brw_opcode_desc_from_hw(const struct intel_device_info *devinfo, unsigned hw);

static inline unsigned
brw_opcode_encode(const struct intel_device_info *devinfo, enum opcode opcode)
{
   return brw_opcode_desc(devinfo, opcode)->hw;
}

static inline enum opcode
brw_opcode_decode(const struct intel_device_info *devinfo, unsigned hw)
{
   const struct opcode_desc *desc = brw_opcode_desc_from_hw(devinfo, hw);
   return desc ? (enum opcode)desc->ir : BRW_OPCODE_ILLEGAL;
}

static inline bool
is_3src(const struct intel_device_info *devinfo, enum opcode opcode)
{
   const struct opcode_desc *desc = brw_opcode_desc(devinfo, opcode);
   return desc && desc->nsrc == 3;
}

#ifdef __cplusplus
}
#endif
#endif
