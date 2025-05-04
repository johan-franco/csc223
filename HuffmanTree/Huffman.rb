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
    #currently can't have root node as leaf
    @root = HuffInternalNode.new(nil)

    def build_tree(chawei)
        #transform all of input array elements into leaf nodes
        leaf_nodes = chawei.map { |char, weight| HuffLeafNode.new(char,weight) }
        
        #sort array of leaf nodes by weight to build from the ground up ()
        nodes = leaf_nodes.sort_by { |leafnode| leafnode.weight }

        while nodes.size != 1
            #need to take 2 elements from nodes out to create an internal node 
            #then add internal node back into tree
            #this should loop until only root element is left

    #need build_tree method. need to take in in array and start building from ground up
end