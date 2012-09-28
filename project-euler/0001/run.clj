
(reduce + (filter 
                  #(or 
                        (= (mod %1 3) 0)
                        (= (mod %1 5) 0))
                  (range 1000)))
