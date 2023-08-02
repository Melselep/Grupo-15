import { measureExecutionTime, array } from "./bench.js";

measureExecutionTime("array#sort", () => array.sort(), process.argv[2], process.argv[3]);
