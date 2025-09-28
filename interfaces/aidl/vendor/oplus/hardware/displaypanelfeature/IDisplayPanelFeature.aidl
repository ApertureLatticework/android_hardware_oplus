/*
 * Copyright (C) 2025 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

package vendor.oplus.hardware.displaypanelfeature;

@VintfStability
interface IDisplayPanelFeature {
    int getDisplayPanelFeatureValue(in int featureId, out int[] featureValue);
    int setDisplayPanelFeatureValue(in int featureId, in int[] featureValue);
    int getDisplayPanelInfo(in int featureId, out String[] featureInfo);
}
