#include "get_edge_names.h"

#include "get_edge_names_demo.impl"

#include <cassert>
#include <iostream>
#include "add_named_edge.h"
#include "get_n_edges.h"
#include "get_n_vertices.h"
#include "create_k2_graph.h"
#include "create_empty_undirected_named_edges_and_vertices_graph.h"
#include "create_named_edges_and_vertices_k3_graph.h"

void get_edge_names_test() noexcept
{
  {
    auto g = create_empty_undirected_named_edges_and_vertices_graph();
    const std::string edge_name_1{"Eugene"};
    const std::string edge_name_2{"Another Eugene"};
    add_named_edge(edge_name_1, g);
    add_named_edge(edge_name_2, g);
    const std::vector<std::string> expected_names{edge_name_1, edge_name_2};
    const std::vector<std::string> edge_names{get_edge_names(g)};
    assert(expected_names == edge_names);
  }
  //Named K3 graph
  {
    const auto g = create_named_edges_and_vertices_k3_graph();
    const std::vector<std::string> expected_names{"AB", "BC", "CA"};
    const std::vector<std::string> edge_names{get_edge_names(g)};
    assert(expected_names == edge_names);
  }
  get_edge_names_demo();
  std::cout << __func__ << ": OK" << '\n';
}
