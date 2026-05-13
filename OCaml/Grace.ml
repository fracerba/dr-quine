(*
	this program is a quine, it self-replicates its own source code when executed.
*)

let file = "Grace_kid.ml"
let str = "(*\n\tthis program is a quine, it self-replicates its own source code when executed.\n*)\n\nlet file = \"Grace_kid.ml\"\nlet str = "
let str2 = "\n\nlet () =\n\ttry\n\t\tlet outfile = open_out file in\n\t\tPrintf.fprintf outfile \"%s%S%s%S%s\" str str \"\\nlet str2 = \" str2 str2;\n\t\tclose_out_noerr outfile\n\twith Sys_error err -> prerr_endline err"

let () =
	try
		let outfile = open_out file in
		Printf.fprintf outfile "%s%S%s%S%s" str str "\nlet str2 = " str2 str2;
		close_out_noerr outfile
	with Sys_error err -> prerr_endline err