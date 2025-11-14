/*
<<<<<<< HEAD
 * Copyright (C) 2025 The LineageOS Project
 *
=======
 * SPDX-FileCopyrightText: 2025 The LineageOS Project
>>>>>>> 03e2ea4da32b93b5f5f80d42fbaa8da6c7738d06
 * SPDX-License-Identifier: Apache-2.0
 */

package vendor.oplus.hardware.displaypanelfeature;

@VintfStability
interface IDisplayPanelFeature {
    int getDisplayPanelFeatureValue(int featureId, inout int[] featureValues);
    int setDisplayPanelFeatureValue(int featureId, in int[] featureValues);
    int getDisplayPanelInfo(int featureId, out List<String> panelInfo);
}
