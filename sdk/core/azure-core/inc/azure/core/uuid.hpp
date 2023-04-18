// Copyright (c) Microsoft Corporation. All rights reserved.
// SPDX-License-Identifier: MIT

/**
 * @file
 * @brief Universally unique identifier.
 */

#pragma once

#include "azure/core/platform.hpp"

#include <cstring>
#include <string>

namespace Azure { namespace Core {
  /**
   * @brief Universally unique identifier.
   */
  class Uuid final {

  private:
    static constexpr size_t UuidSize = 16;

    uint8_t m_uuid[UuidSize];

  private:
    Uuid(uint8_t const uuid[UuidSize]) { std::memcpy(m_uuid, uuid, UuidSize); }

  public:
    /**
     * @brief Gets Uuid as a string.
     * @details A string is in canonical format (4-2-2-2-6 lowercase hex and dashes only).
     */
    std::string ToString();

    /**
     * @brief Creates a new random UUID.
     *
     */
    static Uuid CreateUuid();
  };
}} // namespace Azure::Core
