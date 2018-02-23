-- the debug mode
if is_mode("debug") then
    
    -- enable the debug symbols
    set_symbols("debug")

    -- disable optimization
    set_optimize("none")
end

-- the release mode
if is_mode("release") then

    -- set the symbols visibility: hidden
    set_symbols("hidden")

    -- enable fastest optimization
    set_optimize("fastest")

    -- strip all symbols
    set_strip("all")
end

target("demo")
    set_kind("binary")
    set_targetdir("app/")
    add_files("src/*.c")
    add_files("src/ui/views/*.c")
    add_files("src/ui/helpers/*.c")
    add_includedirs("include", "../include", "../../LCUI/include", "../vendor/include")
    add_linkdirs("../vendor/lib", "../dist/lib")
    add_links("LCUIEx", "LCUI")
    before_build(function (target)
        if is_os("windows") then
            os.cp("../dist/lib/*.dll", "app/")
        else
            os.cp("../dist/lib/*.so", "app/")
        end
        os.cp("../dist/assets/*", "app/assets")
    end)
    if is_os("windows") then
        add_rpathdirs(".", "/usr/local/lib")
    end

