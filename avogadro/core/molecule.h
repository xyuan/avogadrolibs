/******************************************************************************

  This source file is part of the Avogadro project.

  Copyright 2011-2012 Kitware, Inc.

  This source code is released under the New BSD License, (the "License").

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

******************************************************************************/

#ifndef AVOGADRO_CORE_MOLECULE_H
#define AVOGADRO_CORE_MOLECULE_H

#include "avogadrocore.h"

#include <vector>

#include "atom.h"
#include "bond.h"
#include "graph.h"
#include "variantmap.h"
#include "vector.h"

namespace Avogadro {
namespace Core {

class AVOGADROCORE_EXPORT Molecule
{
public:
  // construction and destruction
  Molecule();
  virtual ~Molecule();

  // properties
  size_t size() const;
  bool isEmpty() const;
  void setData(const std::string &name, const Variant &value);
  Variant data(const std::string &name) const;
  void setDataMap(const VariantMap &map);
  const VariantMap& dataMap() const;
  VariantMap& dataMap();

  std::vector<unsigned char>& atomicNumbers();
  const std::vector<Vector2>& atomPositions2d() const;
  std::vector<Vector2>& atomPositions2d();
  const std::vector<Vector3>& atomPositions3d() const;
  std::vector<Vector3>& atomPositions3d();
  const std::vector<unsigned char>& atomicNumbers() const;
  std::vector<std::pair<size_t, size_t> >& bondPairs();
  const std::vector<std::pair<size_t, size_t> >& bondPairs() const;
  std::vector<unsigned char>& bondOrders();
  const std::vector<unsigned char>& bondOrders() const;
  Graph& graph();
  const Graph& graph() const;

  // structure
  Atom addAtom(unsigned char atomicNumber);
  Atom atom(size_t index) const;
  size_t atomCount() const;
  Bond addBond(const Atom &a, const Atom &b, unsigned char bondOrder = 1);
  Bond bond(size_t index) const;
  Bond bond(const Atom &a, const Atom &b) const;

  /*!
   * \brief Get all bonds to \p a.
   * \return A vector of bonds to the supplied atom \p a.
   */
  std::vector<Bond> bonds(const Atom &a);

  size_t bondCount() const;

protected:
  mutable Graph m_graph; // A transformation of the molecule to a graph.
  mutable bool m_graphDirty; // Should the graph be rebuilt before returning it?
  VariantMap m_data;
  std::vector<unsigned char> m_atomicNumbers;
  std::vector<Vector2> m_positions2d;
  std::vector<Vector3> m_positions3d;
  std::vector<std::pair<size_t, size_t> > m_bondPairs;
  std::vector<unsigned char> m_bondOrders;

  void updateGraph() const;
};

} // end Core namespace
} // end Avogadro namespace

#endif // AVOGADRO_CORE_MOLECULE_H
