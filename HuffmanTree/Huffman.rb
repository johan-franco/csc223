class HuffLeafNode
    attr_accessor :char, :weight
    def initialize(char, weight = nil)
        @char = char
        @weight = weight
    end
  
    def isLeaf
        return true
    end

end

class HuffInternalNode
    attr_accessor :left, :right, :weight

    def initialize(weight, left = nil, right = nil)
        @weight = weight
        @left = left 
        @right = right 
    end

    def isLeaf
        return false
    end

end

class HuffTree
    attr_reader :root

    def initialize(frequency)
        @leaf_nodes = frequency
        @root = build_tree(@leaf_nodes)
    end
    

    def build_tree(chawei)
        #transform all of input array elements into leaf nodes
        nodes = chawei.map { |char, weight| HuffLeafNode.new(char,weight) }
        

        while nodes.size != 1
            #sort array of leaf nodes by weight to build from the ground up ()
            nodes = nodes.sort_by { |node| node.weight }

            #take the first element in array and assign to left as it should have the lowest weight
            left = nodes.shift
            right = nodes.shift

            internal_weight = left.weight + right.weight

            internal = HuffInternalNode.new(internal_weight, left,right)
            
            #put internal node back into array, this will loop until only root element is left
            nodes << internal
        end

        return nodes.first
    end

    def insert(leaf_node)
        @leaf_nodes << leaf_node
        @root = build_tree(@leaf_nodes)
    end

end

test_frequencies = [
  ['a', 5],
  ['b', 9],
  ['c', 12],
  ['d', 13],
  ['e', 16],
  ['f', 45]         
]

#need to work on pretty print
tree = HuffTree.new(test_frequencies)
puts "\nTree structure:"
#tree.root.pretty_print

# testing root weight
expected_root_weight = test_frequencies.sum { |char, weight| weight }
actual_root_weight = tree.root.weight
puts "\nVerification:"
puts "Expected root weight: #{expected_root_weight}"
puts "Actual root weight:   #{actual_root_weight}"

# testing insert
tree.insert(['g', 8])
puts "\nUpdated tree structure:"
tree.root.pretty_print
