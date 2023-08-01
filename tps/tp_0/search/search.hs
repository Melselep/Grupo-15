import Data.Time
import Data.List(find)

timeFunction :: IO () -> IO ()
timeFunction function = do
   startTime <- getCurrentTime
   function
   endTime <- getCurrentTime
   let diff = diffUTCTime endTime startTime
   putStrLn $ "Execution Time: " ++ show diff


lista :: [Int]
lista = [
 69, 66, 87, 49, 68, 27, 37, 27, 99, 40, 55, 42, 78, 97, 65, 72, 30, 92, 81, 76, 17, 23, 35, 40,
 14, 79, 67, 36, 9, 65, 70, 65, 21, 34, 4, 22, 77, 39, 44, 70, 71, 31, 24, 1, 72, 83, 30, 85, 48,
 78, 1, 12, 26, 80, 70, 78, 77, 70, 70, 61, 58, 31, 51, 89, 8, 96, 16, 82, 34, 10, 50, 57, 15,
 62, 22, 5, 68, 44, 12, 74, 19, 70, 12, 43, 2, 14, 94, 40, 25, 64, 2, 35, 3, 38, 19, 7, 63, 98,
 47, 44
    ]

busqueda :: IO()
busqueda = do 
    print (find (==26) lista)

main :: IO ()
main = do
   timeFunction busqueda