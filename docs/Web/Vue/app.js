//  首先，我们需要创建一个 Vue 应用实例。我们可以通过调用 Vue.createApp() 函数来创建一个应用实例。
const app = Vue.createApp(
    {
        //在这个函数中，我们可以定义应用实例的数据、方法和生命周期钩子。
        data() {
            return {
                message: 'Hello, Vue 3!'
            }
        },
        methods: {
            reverseMessage() {
                this.message = this.message
                    .split('')
                    .reverse()
                    .join('')
            }
        },
        // 在这个函数中，我们可以定义应用实例的生命周期钩子。
        mounted() {
            console.log('App mounted!')
        }
    }
)

// 通过调用 app.mount() 函数并传入一个选择器字符串，我们可以将应用实例挂载到页面上，这样应用实例就可以渲染页面了。
app.mount('#app')

// 通过调用 app.component() 函数，我们可以注册一个全局组件。这样，我们就可以在模板中使用这个组件了。
app.component('my-component', {
    template: '<div>A custom component!</div>'
})
