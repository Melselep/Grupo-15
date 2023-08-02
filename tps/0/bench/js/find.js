import { measureExecutionTime, array } from "./bench.js";
import { BENCH_ARGS } from "./args.js";

measureExecutionTime(
	"array#find",
	() => array.find((value) => value == 569),
	BENCH_ARGS.WM_ITERATIONS,
	BENCH_ARGS.ITERATIONS
);
