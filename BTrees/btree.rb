# still need to account for insert where finalnode's parent isn't rootnode.. maybe i could just have a var that represents that node?

class RootNode
    attr_accessor :maxval, :values, :paths
    def initialize(val = [])
        @maxval = 4
        @values = val
        @paths = []
    end

    def isRoot
        return true
    end

    def insert(val)
        @values << val
        @values.sort!
        minval = @maxval/2 
        median = @values[minval]
        if @values.length() > @maxval
            if paths.empty?
                ##if root is full without having any nodes it is pointing to
                @paths[0] = Node.new(@values[0...minval])
                @paths[1] = Node.new(@values[minval+1..-1])
                @values = @values[@maxval/2]
                @values = [median]
                return
            else
                #if root is full with path to nodes being present
                lessernode = Node.new(@values[0...minval])
                greaternode = Node.new(@values[minval+1..-1])
                lessernode.paths = @paths[0..minval]
                greaternode.paths = @paths[minval+1..-1]
                @root.paths = [lessernode, greaternode]
                @values = [median]                
                return
            end
        end
    
    end

    def to_s(indent=0)
        s = "#{'  '*indent}Root: #{@values.inspect}\n"
        @paths.each { |p| s += p.to_s(indent+1) }
        return s
    end

    def update_paths
        return
    end

end

class Node < RootNode
    attr_accessor :minval
    def initialize(val = [])
        super
        @values = val
        @minval = @maxval/2
    end

    def isRoot
        return false
    end

    def traverse(val)
        return self if @paths.empty?        
        count = 0
        until val < self.values[count] do
            count+=1
            #if this occurs that means val is greater than all of them 
            break if count == @root.values.length
        end
        nextnode = self.paths[count]
        nextnode.traverse
    end

    def to_s(indent=0)
        s = "#{'  '*indent}Node: #{@values.inspect}\n"
        @paths.each { |p| s += p.to_s(indent+1) }
        return s
    end

    def splitnodes
        right = Node.new(@values[minval+1..-1])
        @values = @values[0...minval]
        return right
    end
end

class BTree
    attr_reader :root
    def initialize
        @root = RootNode.new()
    end

    def insert(val)
        if @root.paths.empty?
            @root.insert(val)
        else
            finalnode = traverse(val)
            finalnode.values << val
            finalnode.values.sort!
            if finalnode.values.length > finalnode.maxval
                median = finalnode.values[finalnode.maxval/2]
                @root.values << median
                newright = finalnode.splitnodes
                @root.paths << newright
            end
        end
    end

    def traverse(val)
        #traverse using val and prob return node that it should return
        count = 0
        until val < @root.values[count] do
            count +=1
            #if this occurs that means val is greater than all of them 
            break if count == @root.values.length
        end
        nextnode = @root.paths[count]
        if nextnode.paths.empty?
            return nextnode

        else 
            return nextnode.traverse(val)
        end
            
    end

    def visualize
        puts @root.to_s
    end
end





btree = BTree.new

puts "Inserting 3, 7, 1, 8, 2, 5, 4, 6, 9"
[3, 7, 1, 8, 2, 5, 4, 6, 9].each do |val|
  btree.insert(val)
  puts "After inserting #{val}:"
  btree.visualize
  puts "---------------------"
end

puts "\nFinal B-tree structure:"
btree.visualize