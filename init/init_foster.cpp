/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"
#include <stdio.h>
#include <string.h>

void vendor_load_properties()
{
    std::string platform = "";
    std::string model = "";

    platform = property_get("ro.board.platform");
    if (strncmp(platform.c_str(), ANDROID_TARGET, PROP_VALUE_MAX))
        return;

    model = property_get("ro.hardware");
    if (!model.compare("foster_e_hdd")) { // check cpuinfo hardware identifier
        /* SATA Model */
        property_set("ro.build.fingerprint", "nvidia/foster_e_hdd/t210:6.0/MRA58K/41937_667.2671:user/release-keys");
        property_set("ro.build.description", "foster_e_hdd-user 6.0 MRA58K 41937_667.2671 release-keys");
        property_set("ro.product.name", "foster_e_hdd");
    } else {
        /* EMMC Model */
        property_set("ro.build.fingerprint", "nvidia/foster_e/t210:6.0/MRA58K/41937_667.2671:user/release-keys");
        property_set("ro.build.description", "foster_e-user 6.0 MRA58K 41937_667.2671 release-keys");
        property_set("ro.product.name", "foster_e");
    }

    property_set("ro.build.product", "foster");
    property_set("ro.product.device", "foster");
    property_set("ro.product.model", "SHIELD Android TV");
    ERROR("Setting build properties for %s model\n", model.c_str());
}
