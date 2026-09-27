/*
    vulkan_ad.cpp -- instantiates the drjit.vulkan.ad.* namespace

    Dr.Jit: A Just-In-Time-Compiler for Differentiable Rendering
    Copyright 2022, Realistic Graphics Lab, EPFL.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/

#include "vulkan.h"
#include "random.h"
#include "texture.h"
#include <drjit/autodiff.h>

#if defined(DRJIT_ENABLE_VULKAN)
void export_vulkan_ad(nb::module_ &m) {
    using Guide = dr::VulkanDiffArray<float>;

    ArrayBinding b;
    dr::bind_all<Guide>(b);
    bind_rng<Guide>(m);
    bind_texture_all<Guide>(m);

    m.attr("Float32") = m.attr("Float");
    m.attr("Int32") = m.attr("Int");
    m.attr("UInt32") = m.attr("UInt");

    // Create Event alias from non-AD module
    nb::module_ vulkan_module = nb::module_::import_("drjit.vulkan");
    m.attr("Event") = vulkan_module.attr("Event");
}
#endif
