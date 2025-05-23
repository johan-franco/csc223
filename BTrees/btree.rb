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
                @paths.concat(lessernode.paths, greaternode.paths) 
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
    def initialize(val = [], par = nil)
        super
        @values = val
        @minval = @maxval/2
        @parent = par
    end

    def isRoot
        return false
    end

    def traverse(val)
        return self if @paths.empty?        
        count = 0
        until val <= self.values[count] do
            count+=1
            #if this occurs that means val is greater than all of them 
            break if count == @root.values.length
        end
        if val == self.values[count]
            return self
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

    def delete(key)
        @keys.delete(key)
        check()
    end

    def check
        if @keys.length < @minval
            return true
        else
            return false
        end
    end

    def merge(sibling)
        par = @parent
        if sibling.values[0] < @values[0]
            leftchild = sibling
            rightchild = self
        else
            rightchild = sibling
            leftchild = self
        end

        count = 0
        val = rightchild.values[0]
        until val <= par.values[count] do
            count+=1
        end

        prevsep = par.values[count-1]
        par.values.delete(prevsep)

        newsep = right_child.values[0]
        right_child.values.delete(newsep)

        merging 
        if val
        
    end

end

class BTree
    attr_reader :root
    def initialize
        @root = RootNode.new()
    end

    def insert(val)
        if @root.paths.empty? or @root.values.length > @root.maxval
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

    def parenttraverse(val)
        #traverse using val and prob return node that it should return
        count = 0
        until val <= @root.values[count] do
            count +=1
            #if this occurs that means val is greater than all of them 
            break if count == @root.values.length
        end
        if val == @root.values[count]
            return @root
        end
        nextnode = @root.paths[count]
        if nextnode.paths.empty?
            return nextnode

        else 
            return nextnode.traverse(val)
        end
            
    end

    def delete(val)
        deletenode = traverse(val)

        if deletenode.isRoot

    def visualize
        puts @root.to_s
    end

end





btree = BTree.new

puts "Inserting 3, 7, 1, 8, 2, 5, 4, 6, 9"
[3, 7, 1, 8, 2, 5, 4, 6, 9, 20, 40, 50, 80, 100, 120, 140, 150, 180].each do |val|
  btree.insert(val)
  puts "After inserting #{val}:"
  btree.visualize
  puts "---------------------"
end

puts "\nFinal B-tree structure:"
btree.visualize