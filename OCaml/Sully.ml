let () =
	let n = 5 in
	if n > 0 then
		try
			let exe = "Sully_" ^ string_of_int (n - 1) in
			let file = exe ^ ".ml" in
			let str = "let () =\n\tlet n = " in
			let str2 = " in\n\tif n > 0 then\n\t\ttry\n\t\t\tlet exe = \"Sully_\" ^ string_of_int (n - 1) in\n\t\t\tlet file = exe ^ \".ml\" in\n\t\t\tlet str = " in
			let str3 = " in\n\t\t\tlet outfile = open_out file in\n\t\t\tPrintf.fprintf outfile \"%s%d%s%S%s%S%s%S%s\" str (n - 1) str2 str \" in\\n\\t\\t\\tlet str2 = \" str2 \" in\\n\\t\\t\\tlet str3 = \" str3 str3;\n\t\t\tclose_out_noerr outfile;\n\t\t\tif Sys.command (\"ocamlopt -o \" ^ exe ^ \" \" ^ file) = 0 then\n\t\t\t\tignore (Sys.command (\"./\" ^ exe))\n\t\twith Sys_error err -> prerr_endline err" in
			let outfile = open_out file in
			Printf.fprintf outfile "%s%d%s%S%s%S%s%S%s" str (n - 1) str2 str " in\n\t\t\tlet str2 = " str2 " in\n\t\t\tlet str3 = " str3 str3;
			close_out_noerr outfile;
			if Sys.command ("ocamlopt -o " ^ exe ^ " " ^ file) = 0 then
				ignore (Sys.command ("./" ^ exe))
		with Sys_error err -> prerr_endline err