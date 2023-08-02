module Main where
import System.Environment (getArgs)   
import Data.List(find)
import Bench (bench, list) 

findEl :: Int -> Maybe Int
findEl el = find (==el) list

main :: IO ()
main = do
  args <- getArgs
  let wmIterations = read (head args) :: Int
  let iterations = read (last args) :: Int 
  bench "list#find" findEl 569 wmIterations iterations
 
