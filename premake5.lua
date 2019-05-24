library("zboost", {
	includedirs = {"include"}
});

solution("zboost", function()
	project("zboost", function()
		category ("StaticLib");
		directory("include/boost");
		sourcedirs("include");
	end);

	project("helloworld", function()
		category ("ConsoleApp");
		directory("tests/helloworld");
		depends("zboost");
	end);
end);
