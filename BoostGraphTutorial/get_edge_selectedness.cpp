#include "get_edge_selectedness.h"

#include "get_edge_selectedness_demo.impl"

#include <cassert>
#include <iostream>
#include "add_custom_and_selectable_edge.h"
#include "create_empty_undirected_custom_and_selectable_edges_and_vertices_graph.h"
#include "get_edge_selectedness.h"

void get_edge_selectedness_test() noexcept
{
  {
    auto g
      = create_empty_undirected_custom_and_selectable_edges_and_vertices_graph();
    const auto vd_a
      = add_custom_and_selectable_edge(my_custom_edge(), false, g);
    assert(get_edge_selectedness(vd_a, g) == false);
    const auto vd_b
      = add_custom_and_selectable_edge(my_custom_edge(), true, g);
    assert(get_edge_selectedness(vd_b, g) == true);
  }
  get_edge_selectedness_demo();
  
}