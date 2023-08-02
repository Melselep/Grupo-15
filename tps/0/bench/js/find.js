import { measureExecutionTime, array } from "./bench.js";

measureExecutionTime(
	"array#find",
	() => array.find((value) => value == 569),
	process.argv[2],
	process.argv[3]
);
