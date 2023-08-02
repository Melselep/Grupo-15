run_benchmarks() {
    echo "====================== Running benchmarks ====================== \n" 
    cd $PWD/bench
    echo "Haskell:" 
    cd haskell && cabal build  --ghc-options=-W && cabal run
    echo ""
    echo "Javascript:"
    cd ../js && npm start
}

run_benchmarks

