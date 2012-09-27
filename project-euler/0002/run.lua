
function f(a, b)
    return b, a+b
end


sum =0
a = 0
b = 1
while a < 4000000 do
    if a%2 == 0 then
        sum = sum + a
    end
    a, b = f(a, b)
end
print(sum)

