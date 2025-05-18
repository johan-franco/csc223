class BTreeNode
  attr_accessor :keys, :children, :leaf

  def initialize(t, leaf = true)
    @t = t                  # Minimum degree (defines max keys = 2t-1)
    @keys = []              # Keys in node
    @children = []          # Child pointers
    @leaf = leaf            # Leaf node or not
  end

  # Insert key in node that is guaranteed not full
  def insert_non_full(key)
    i = @keys.size - 1

    if @leaf
      # Insert key into correct position in keys array
      @keys << nil
      while i >= 0 && key < @keys[i]
        @keys[i + 1] = @keys[i]
        i -= 1
      end
      @keys[i + 1] = key
    else
      # Find child to insert into
      while i >= 0 && key < @keys[i]
        i -= 1
      end
      i += 1

      # If child full, split it
      if @children[i].keys.size == 2 * @t - 1
        split_child(i)
        if key > @keys[i]
          i += 1
        end
      end
      @children[i].insert_non_full(key)
    end
  end

  # Split child node at index i
  #appears to be error with this as there is a parent node with just 9 as val that has 3 children somehow
  def split_child(i)
    y = @children[i]
    z = BTreeNode.new(@t, y.leaf)

    # Transfer second half keys to z
    z.keys = y.keys[@t..-1]
    y.keys = y.keys[0...@t - 1]

    # Transfer children if not leaf
    unless y.leaf
      z.children = y.children[@t..-1]
      y.children = y.children[0...@t]
    end

    @children.insert(i + 1, z)
    @keys.insert(i, y.keys.pop)
  end
end

class BTree
  def initialize(t = 3)  # t=3 => max 5 keys per node, so max 4 keys before split
    @t = t
    @root = BTreeNode.new(t)
  end

  def insert(key)
    r = @root
    if r.keys.size == 2 * @t - 2
      s = BTreeNode.new(@t, false)
      s.children << r
      s.split_child(0)
      i = key < s.keys[0] ? 0 : 1
      s.children[i].insert_non_full(key)
      @root = s
    else
      r.insert_non_full(key)
    end
  end

  def print_tree
    print_btree(@root)
  end

  private

  def print_btree(node, prefix = "", is_last = true)
    return if node.nil?

    puts prefix + (is_last ? "└── " : "├── ") + node.keys.inspect

    new_prefix = prefix + (is_last ? "    " : "│   ")

    node.children.each_with_index do |child, index|
      is_last_child = (index == node.children.size - 1)
      print_btree(child, new_prefix, is_last_child)
    end
  end
end


btree = BTree.new
#after modifying the values it actually doesn't have a maximum of 4 nodes  before it splits. I believe this is because it 
# checks if the node is equal to 2t - 1 before you insert the value. So you could have 4 keys and be inserting a new one and have it fail to
# satisfy the condition because it checked before inserting meaning if you were to print the true after that insertion it would show a node with 5 keys
# changing the condition to 2t -2 causes split to occur at proper time but theres an issue with spliiting so that isn't working properly
[6, 9, 10, 12, 13, 14, 4, 2, 8, 23, 100, 28, 75, 47, 100, 90, 75, 22, 23, 45, 189, 200, 11, 12, 34, 56, 78, 89, 15, 16].each do |val|
    #when you print you'll notice 10 is actually lost it doesn't appear at all
  btree.insert(val)
end

btree.print_tree