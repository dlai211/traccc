/** TRACCC library, part of the ACTS project (R&D line)
 *
 * (c) 2022-2024 CERN for the benefit of the ACTS project
 *
 * Mozilla Public License Version 2.0
 */

#pragma once

// Project include(s).
#include "traccc/definitions/hints.hpp"
#include "traccc/definitions/qualifiers.hpp"
#include "traccc/edm/cell.hpp"
#include "traccc/edm/measurement.hpp"

// VecMem include(s).
#include <vecmem/containers/data/vector_view.hpp>

namespace traccc::device {

/// Function which looks for cells which share the same "parent" index and
/// aggregates them into a cluster.
///
/// @param[in] cells    collection of cells
/// @param[in] modules  collection of modules to which the cells are linked to
/// @param[in] f        array of "parent" indices for all cells in this
/// partition
/// @param[in] start    partition start point this cell belongs to
/// @param[in] end      partition end point this cell belongs to
/// @param[in] cid      current cell id
/// @param[out] out     cluster to fill
TRACCC_HOST_DEVICE
inline void aggregate_cluster(
    const cell_collection_types::const_device& cells,
    const cell_module_collection_types::const_device& modules,
    const vecmem::device_vector<details::index_t>& f_view, unsigned int start,
    unsigned int end, unsigned short cid, measurement& out,
    vecmem::data::vector_view<unsigned int> cell_links, unsigned int link);

}  // namespace traccc::device

// Include the implementation.
#include "traccc/clusterization/device/impl/aggregate_cluster.ipp"
