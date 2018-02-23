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
        os.cp("dist/lib/" .. target.filename("*", "shared"), "app/")
        os.trycp("dist/assets/*", "app/assets")
    end)

    if is_mode("release") then
        set_symbols("hidden")
    end

    if not is_os("windows") then
        add_rpathdirs("/usr/local/lib")
    end
