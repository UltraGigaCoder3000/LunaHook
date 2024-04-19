﻿   
#define ALREADY_INJECTED L"已经注入" 
#define NEED_32_BIT L"架构不匹配: 请尝试使用32位注入此进程" 
#define NEED_64_BIT L"架构不匹配: 请尝试使用64位注入此进程" 
#define INJECT_FAILED L"注入失败" 
#define INVALID_CODEPAGE L"无法转换文本 (无效的代码页?)" 
#define PIPE_CONNECTED u8"管道已连接" 
#define INSERTING_HOOK u8"注入钩子: %s" 
#define REMOVING_HOOK u8"移除钩子: %s" 
#define TOO_MANY_HOOKS u8"钩子数量已达上限: 无法注入" 
#define HOOK_SEARCH_STARTING u8"开始搜索钩子" 
#define HOOK_SEARCH_INITIALIZING u8"初始化钩子搜索 (%f%%)" 
#define NOT_ENOUGH_TEXT u8"文本长度不足, 无法精确搜索" 
#define HOOK_SEARCH_INITIALIZED u8"搜索初始化完成, 创建了 %zd 个钩子" 
#define MAKE_GAME_PROCESS_TEXT u8"请点击游戏区域, 在接下来的 %d 秒内使游戏强制处理文本" 
#define HOOK_SEARCH_FINISHED u8"钩子搜索完毕, 找到了 %d 条结果" 
#define OUT_OF_RECORDS_RETRY u8"搜索结果已达上限, 如果结果不理想, 请重试(默认最大记录数增加)" 
#define FUNC_MISSING u8"函数不存在" 
#define MODULE_MISSING u8"模块不存在" 
#define GARBAGE_MEMORY u8"内存一直在改变，无法有效读取" 
#define SEND_ERROR u8"Sender 错误 (可能是由于错误或不稳定的 H-code) ： %s" 
#define READ_ERROR u8"Reader 错误 (可能是由于错误或不稳定的 R-code) ： %s" 
#define SearchForHooks_ERROR u8"搜索钩子错误 : 内存移除，尝试重新分配 %d" 
#define ResultsNum u8"%d 个结果被找到" 
#define HIJACK_ERROR u8"Hijack 错误" 
#define COULD_NOT_FIND u8"无法找到文本" 
#define CONSOLE L"控制台" 
#define InvalidLength  u8"可能存在错误 (无效的文本长度 %d 出现 %s)" 
#define InsertHookFailed u8"钩子注入失败 %s" 
#define Match_Error u8"匹配 %s 引擎时发生错误" 
#define Attach_Error u8"连接到 %s 引擎时发送错误" 
#define MatchedEngine u8"匹配到 %s 引擎" 
#define ConfirmStop u8"确认是 %s 引擎, 停止匹配" 
#define Attach_Stop u8"成功连接到 %s 引擎" 
#define ProcessRange u8"获取到进程内存地址范围 0x%p 到 0x%p" 
#define WarningDummy u8"警告，注入的进程内存很小，可能是无用进程!" 
#define WndSelectProcess L"选择进程" 
#define WndLunaHostGui L"LunaHost Gui" 
#define WndSetting L"设置" 
#define WndPlugins L"插件" 
#define NotifyInvalidHookCode L"特殊码无效" 
#define BtnSelectProcess L"选择进程" 
#define BtnDetach L"从游戏分离" 
#define BtnSaveHook L"保存钩子" 
#define BtnShowSettingWindow L"设置" 
#define BtnAttach L"注入进程" 
#define BtnRefresh L"刷新" 
#define BtnToClipboard L"复制到剪贴板" 
#define BtnReadOnly L"文本框只读" 
#define BtnInsertUserHook L"插入特殊码" 
#define BtnSearchHook L"搜索钩子" 
#define BtnPlugin L"插件" 
#define LblFlushDelay L"刷新延迟" 
#define LblFilterRepeat L"过滤重复文本" 
#define LblCodePage L"默认代码页" 
#define LblMaxBuff L"最大缓冲区长度"
#define LblMaxHist L"最大缓存文本长度"
#define LblAutoAttach L"自动附加"
#define LblAutoAttach_savedonly L"自动附加 (仅限保存过配置的游戏)"
#define MenuCopyHookCode L"复制特殊码" 
#define MenuRemoveHook L"移除钩子" 
#define MenuDetachProcess L"离开进程" 
#define MenuRemeberSelect L"记住选择的钩子" 
#define MenuForgetSelect L"忘掉选择的钩子" 
#define MenuAddPlugin L"添加插件" 
#define MenuRemovePlugin L"移除插件" 
#define MenuPluginRankUp L"上移" 
#define MenuPluginRankDown L"下移" 
#define MenuPluginEnable L"使用" 
#define DefaultFont L"微软雅黑" 
#define CantLoadQtLoader L"无法加载QtLoader.dll"
#define InvalidPlugin L"插件无效！"
#define InvalidDll L"Dll无效！"
#define InvalidDump L"重复！"
#define MsgError L"错误"
#define SEARCH_CJK L"搜索中文/日文/韩文"
#define HS_SETTINGS L"设置"
#define BtnOk L"确定"
#define HS_START_HOOK_SEARCH L"开始搜索钩子"
#define HS_SEARCH_PATTERN L"搜索匹配特征 (hex byte array)"
#define HS_SEARCH_DURATION L"搜索持续时间 (ms)"
#define HS_SEARCH_MODULE L"搜索指定模块"
#define HS_PATTERN_OFFSET L"相对于特征地址的偏移值"
#define HS_MAX_HOOK_SEARCH_RECORDS L"搜索结果达到上限"
#define HS_MIN_ADDRESS L"起始地址 (hex)"
#define HS_MAX_ADDRESS L"结束地址 (hex)"
#define HS_STRING_OFFSET L"字符串偏移值 (hex)"
#define HS_HOOK_SEARCH_FILTER L"结果必须匹配的正则表达式"
#define HS_TEXT L"文本"
#define HS_CODEPAGE L"代码页"
#define HS_SEARCH_FOR_TEXT L"搜索指定文本"
#define VersionLatest L"最新版本"
#define VersionCurrent L"当前版本"
#define ProjectHomePage L"项目主页： https://github.com/HIllya51/LunaHook"
#define LIST_HOOK L"Hook"
#define LIST_TEXT L"文本"
#define PROC_CONN L"进程已连接 %d"
#define PROC_DISCONN L"进程已断开连接 %d"
#define COPYSELECTION L"自动将文本框中选取的文本复制到剪贴板"