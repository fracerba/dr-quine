let () =
	let n = 5 in
	if n > 0 then
		try
			let n =
				if Sys.file_exists "Sully_5.ml" then
					n - 1
				else
					n
			in let exe = "Sully_" ^ string_of_int n in
			let file = exe ^ ".ml" in
			let str = " in\n\tif n > 0 then\n\t\ttry\n\t\t\tlet n =\n\t\t\t\tif Sys.file_exists \"Sully_5.ml\" then\n\t\t\t\t\tn - 1\n\t\t\t\telse\n\t\t\t\t\tn\n\t\t\tin let exe = \"Sully_\" ^ string_of_int n in\n\t\t\tlet file = exe ^ \".ml\" in\n\t\t\tlet str = " in
			let str2 = " in\n\t\t\tlet outfile = open_out file in\n\t\t\tPrintf.fprintf outfile \"%s%d%s%S%s%S%s\" \"let () =\\n\\tlet n = \" n str str \" in\\n\\t\\t\\tlet str2 = \" str2 str2;\n\t\t\tclose_out_noerr outfile;\n\t\t\tif Sys.command (\"ocamlopt -o \" ^ exe ^ \" \" ^ file) = 0 then\n\t\t\t\tignore (Sys.command (\"./\" ^ exe))\n\t\twith Sys_error err -> prerr_endline err" in
			let outfile = open_out file in
			Printf.fprintf outfile "%s%d%s%S%s%S%s" "let () =\n\tlet n = " n str str " in\n\t\t\tlet str2 = " str2 str2;
			close_out_noerr outfile;
			if Sys.command ("ocamlopt -o " ^ exe ^ " " ^ file) = 0 then
				ignore (Sys.command ("./" ^ exe))
		with Sys_error err -> prerr_endline err