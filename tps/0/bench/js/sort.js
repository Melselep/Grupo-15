import { measureExecutionTime, array } from "./bench.js";

measureExecutionTime(
	"array#sort",
	() => array.sort(),
	BENCH_ARGS.WM_ITERATIONS,
	BENCH_ARGS.ITERATIONS
);
