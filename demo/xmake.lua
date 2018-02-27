target("demo")
    set_kind("binary")
    set_default(false)
    set_targetdir("app/")
    add_deps("LCUIEx")
    add_files("src/*.c")
    add_files("src/ui/views/*.c")
    add_files("src/ui/helpers/*.c")
    add_includedirs("include", "../include", "../../LCUI/include", "../vendor/include")

    before_build(function (target)
        if val("plat") == "windows" then
            os.cp("dist/lib/" .. target.filename("*", "shared"), "$(scriptdir)/app/")
            os.cp("vendor/lib/" .. target.filename("*", "shared"), "$(scriptdir)/app/")
        end
        os.trycp("dist/assets/*", "$(scriptdir)/app/assets")
    end)

    if is_mode("release") then
        set_symbols("hidden")
    end

    if not is_os("windows") then
        add_rpathdirs("/usr/local/lib")
    end
