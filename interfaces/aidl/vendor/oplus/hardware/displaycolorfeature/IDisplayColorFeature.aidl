/*
 * Copyright (C) 2025 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

package vendor.oplus.hardware.displaycolorfeature;

import vendor.oplus.hardware.displaycolorfeature.DisplayColorFeatureType;

@VintfStability
interface IDisplayColorFeature {
    /* Feature Status */
    const int FEATURE_DISABLE = 0;
    const int FEATURE_ENABLE  = 1;
    const int FEATURE_MIN     = 2;
    const int FEATURE_MAX     = 3;

    /**
     *  featureValue:
     *  {Status, Enable, Value}
     */
    int getDisplayColorFeatureValue(in DisplayColorFeatureType featureId, out int[] featureValue);
    int setDisplayColorFeatureValue(in DisplayColorFeatureType featureId, in int[] featureValue);
}
