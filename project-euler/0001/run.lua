
function is3or5(n)
    return n%3==0 or n%5==0
end


print(is3or5(3))
print(is3or5(5))
print(is3or5(4))

sum = 0
for i = 1 , 999 do
    if is3or5(i) then
        sum = sum + i
    end
end
print(sum)


    

