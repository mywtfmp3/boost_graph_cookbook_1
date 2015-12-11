#include "create_named_vertices_k2_graph.h"
#include "create_empty_named_vertices_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::property<boost::vertex_name_t,std::string>
>
create_named_vertices_k2_graph() noexcept
{
  auto g = create_empty_named_vertices_graph();
  const auto vd_a = boost::add_vertex(g);
  const auto vd_b = boost::add_vertex(g);
  const auto aer = boost::add_edge(
    vd_a,
    vd_b,
    g
  );
  assert(aer.second);

  auto name_map = get(boost::vertex_name,g);
  name_map[vd_a] = "from";
  name_map[vd_b] = "to";

  return g;
}


