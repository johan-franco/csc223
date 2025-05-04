class HuffLeafNode
    def initialize(char, weight = nil)
        @char = char
        @weight = weight
    end
  
    def isLeaf
        return true
    end
    #getter functions
    def char
        @char
    end
  
    def weight
        @weight
    end

  #setter functions
    def set_weight(new_weight)
        @weight = new_weight
    end
  
    def set_char(new_char)
        @char = new_char
    end

  
end

class HuffInternalNode
    def initialize(weight, left = nil, right = nil)
        @weight = weight
        @left = left 
        @right = right 
    end

    def isLeaf
        return false
    end
  
    #getter functions
    def weight
      @weight
    end
  
    def left
      @left
    end
  
    def right
      @right
    end

  #setter functions
    def set_left(new_left)
      @left = new_left
    end
  
    def set_right(new_right)
      @right = new_right
    end
  
    def set_weight(new_weight)
      @weight = new_weight
    end
  
    #
    def pretty_print(node = self, prefix = '', is_left = true)
      pretty_print(node.right, "#{prefix}#{is_left ? '│   ' : '    '}", false) if node.right
      puts "#{prefix}#{is_left ? '└── ' : '┌── '}#{node.data ? node.data : "nil"}"
      pretty_print(node.left, "#{prefix}#{is_left ? '    ' : '│   '}", true) if node.left
    end
  #
end

class HuffTree

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
        build_tree(@leaf_nodes)
    end

end