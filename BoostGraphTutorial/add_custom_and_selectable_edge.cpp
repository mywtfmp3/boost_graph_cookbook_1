#include "add_custom_and_selectable_edge.h"

#include "add_custom_and_selectable_edge_demo.impl"

#include <cassert>
#include <iostream>

#include "create_empty_undirected_custom_and_selectable_vertices_graph.h"

void add_custom_and_selectable_edge_test() noexcept
{
  //Add 1
  {
    auto g = create_empty_undirected_custom_and_selectable_edges_and_vertices_graph();
    assert(boost::num_vertices(g) == 0);
    assert(boost::num_edges(g) == 0);
    const auto vd_from = boost::add_vertex(g);
    const auto vd_to = boost::add_vertex(g);
    const my_custom_edge edge("X");
    add_custom_and_selectable_edge(vd_from, vd_to, edge, true, g);
    assert(boost::num_vertices(g) == 2);
    assert(boost::num_edges(g) == 1);
  }
  //Add 2
  {
    auto g = create_empty_undirected_custom_and_selectable_edges_and_vertices_graph();
    assert(boost::num_vertices(g) == 0);
    assert(boost::num_edges(g) == 0);
    const my_custom_edge edge_1("X");
    const my_custom_edge edge_2("Y");
    const auto vd_from = boost::add_vertex(g);
    const auto vd_to = boost::add_vertex(g);
    add_custom_and_selectable_edge(vd_from, vd_to, edge_1, true, g);
    add_custom_and_selectable_edge(vd_from, vd_to, edge_2, false, g);
    assert(boost::num_vertices(g) == 2);
    assert(boost::num_edges(g) == 2);
  }
  add_custom_and_selectable_edge_demo();

}


