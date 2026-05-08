(*
	this program is a quine, it self-replicates its own source code when executed.
*)

let file = "Grace_kid.ml"
let str = "(*\n\tthis program is a quine, it self-replicates its own source code when executed.\n*)\n\nlet file = \"Grace_kid.ml\"\nlet str = "
let str2 = "\n\nlet () =\n\ttry\n\t\tlet outfile = open_out file in\n\t\tPrintf.fprintf outfile \"%s%S\\nlet str2 = %S%s\" str str str2 str2\n\twith Sys_error _ -> ()"

let () =
	try
		let outfile = open_out file in
		Printf.fprintf outfile "%s%S\nlet str2 = %S%s" str str str2 str2
	with Sys_error _ -> ()