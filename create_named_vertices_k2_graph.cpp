#include "create_named_vertices_k2_graph.h"

#include "create_named_vertices_k2_graph.impl"

#include "create_named_vertices_k2_graph_demo.impl"

#include <cassert>
#include <iostream>
#include "get_n_edges.h"
#include "get_n_vertices.h"
#include "get_edges.h"
#include "get_vertices.h"
#include "get_edge_descriptors.h"
#include "get_vertex_descriptors.h"
#include "get_vertex_names.h"
#include "create_named_vertices_k2_graph.h"

void create_named_vertices_k2_graph_test() noexcept
{
  const auto g = create_named_vertices_k2_graph();
  const auto vip = get_vertices(g);
  assert(vip.first != vip.second);
  const auto vds = get_vertex_descriptors(g);
  assert(vds.size() == 2);
  const auto eip = get_edges(g);
  assert(eip.first != eip.second);
  const auto eds = get_edge_descriptors(g);
  assert(eds.size() == 1);

  assert(get_n_edges(g) == 1);
  assert(get_n_vertices(g) == 2);
  const std::vector<std::string> expected_names{"A", "B"};
  const std::vector<std::string> vertex_names = get_vertex_names(g);
  assert(expected_names == vertex_names);

  create_named_vertices_k2_graph_demo();
  std::cout << __func__ << ": OK" << '\n';
}

