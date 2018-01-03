def exec(a,b,proc)
    proc.call(a,b)
end

add = proc{|a,b| a+b }
sub = Proc.new{|a,b| a-b}

puts exec(3,4,sub)

'''
def exec2(a,b)
    yield a,b
end
puts exec2(3,4,&sub)
'''
