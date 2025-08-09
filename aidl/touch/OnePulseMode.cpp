/*
 * SPDX-FileCopyrightText: 2025 The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#define LOG_TAG "vendor.lineage.touch-service.oplus"

#include "OnePulseMode.h"

#include <android-base/file.h>
#include <android-base/logging.h>

#include <OplusTouchConstants.h>

using ::android::base::ReadFileToString;
using ::android::base::WriteStringToFile;

namespace {

    constexpr const char* kOnePulseModeEnablePath = "/sys/kernel/oplus_display/pwm_onepulse";

}  // anonymous namespace

namespace aidl {
    namespace vendor {
        namespace lineage {
            namespace touch {

                OnePulseMode::OnePulseMode(std::shared_ptr<IOplusTouch> oplusTouch)
                : mOplusTouch(std::move(oplusTouch)) {}

                ndk::ScopedAStatus OnePulseMode::getEnabled(bool* _aidl_return) {
                    std::string value;

                    if (mOplusTouch) {
                        mOplusTouch->touchReadNodeFile(OplusTouchConstants::DEFAULT_TP_IC_ID,
                                                       OplusTouchConstants::ONEPULSE_MODE_ENABLE_NODE, &value);
                    } else if (!ReadFileToString(kOnePulseModeEnablePath, &value)) {
                        LOG(ERROR) << "Failed to read current OnePulseMode state";
                        return ndk::ScopedAStatus::fromExceptionCode(EX_UNSUPPORTED_OPERATION);
                    }

                    *_aidl_return = value[0] != '0';
                    return ndk::ScopedAStatus::ok();
                }

                ndk::ScopedAStatus OnePulseMode::setEnabled(bool enable) {
                    if (mOplusTouch) {
                        mOplusTouch->touchWriteNodeFileOneWay(OplusTouchConstants::DEFAULT_TP_IC_ID,
                                                              OplusTouchConstants::ONEPULSE_MODE_ENABLE_NODE,
                                                              enable ? "1" : "0");
                    } else if (!WriteStringToFile(enable ? "1" : "0", kOnePulseModeEnablePath, true)) {
                        LOG(ERROR) << "Failed to write OnePulseMode state";
                        return ndk::ScopedAStatus::fromExceptionCode(EX_UNSUPPORTED_OPERATION);
                    }

    const float refreshRate = enable ? 120.0f : 144.0f;

    std::string command = "settings put system peak_refresh_rate " + std::to_string(refreshRate);
    int result = system(command.c_str());

                    return ndk::ScopedAStatus::ok();
                }

            }  // namespace touch
        }  // namespace lineage
    }  // namespace vendor
}  // namespace aidl
